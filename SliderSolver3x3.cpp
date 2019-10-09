#include "SliderSolver3x3.h"

using namespace std;

SliderSolver3x3::SliderSolver3x3(const SliderBoard & board) :
	SliderSolver(board),
	patternDatabase3x3Ptr(nullptr)
{
}

SliderSolver3x3::~SliderSolver3x3()
{
}

void SliderSolver3x3::setDatabasePtr(const PatternDatabase3x3 * patternDatabase3x3Ptr)
{
	this->patternDatabase3x3Ptr = patternDatabase3x3Ptr;
}

FastSlideSequence SliderSolver3x3::solve()
{
	// Do we have a data base to work with?
	if (patternDatabase3x3Ptr == nullptr) {
		// No, return an empty solution
		cerr << "error: " << __FILE__ << " line " << __LINE__
			<< " patternDatabase3x3Ptr = nullptr\n";
		return FastSlideSequence();
	}
	if (patternDatabase3x3Ptr->empty() == true) {
		cerr << "error: " << __FILE__ << " line " << __LINE__
			<< " database is empty\n";

		return FastSlideSequence();
	}

	// else Yes, we have a database
	const PatternDatabase3x3 & database = *patternDatabase3x3Ptr;

	// Reserve enough space in the SliderSequence for 32 slides.
	// The longest a 3x3 slider puzzle should take to solve is 32 slides.
	FastSlideSequence sequence(32);
	
	PatternDatabase3x3::const_iterator it;

	while (!board.isSolved())
	{
		// ======== Show analytics ==============

		board.print();
		cout << "\tDistance to solution: ";

		PatternDatabase3x3::const_iterator distToSolIter =
			database.find(Checksum3x3(board));

		if (distToSolIter == database.end()) {
			cerr << __FILE__ << " line " << __LINE__
				<< "board cannot be solved\n";
			return sequence;
		}

		cout << distToSolIter->second << '\n';

		// -------- Analyze future moves --------

		uint16_t minDist = UINT16_MAX;
		Slide_T minMove = Slide_T::NONE;

		// --- UP
		cout << setw(7) << "UP: ";
		if (board.isSlideUpValid() == true)
		{
			board.slideUpFast();
			uint16_t temp = database.find(Checksum3x3(board))->second;
			cout << temp << '\n';

			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::UP;
			}

			board.slideDownFast();
		}
		else cout << "not valid\n";

		// --- DOWN
		cout << setw(7) << "DOWN: ";
		if (board.isSlideDownValid() == true)
		{
			board.slideDownFast();
			uint16_t temp = database.find(Checksum3x3(board))->second;
			cout << temp << '\n';

			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::DOWN;
			}

			board.slideUpFast();
		}
		else cout << "not valid\n";

		// --- LEFT
		cout << setw(7) << "LEFT: ";
		if (board.isSlideLeftValid() == true)
		{
			board.slideLeftFast();
			uint16_t temp = database.find(Checksum3x3(board))->second;
			cout << temp << '\n';

			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::LEFT;
			}

			board.slideRightFast();
		}
		else cout << "not valid\n";

		// --- RIGHT
		cout << setw(7) << "RIGHT: ";
		if (board.isSlideRightValid() == true)
		{
			board.slideRightFast();
			uint16_t temp = database.find(Checksum3x3(board))->second;
			cout << temp << '\n';

			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::RIGHT;
			}

			board.slideLeftFast();
		}
		else cout << "not valid\n";

		// Push the slide to the solution sequence
		sequence.push_back(minMove);

		// Apply the slide
		board.slideSafe(minMove);
	}

	board.print();

	cout << "\n====== Board is solved ==========\n\n\n";

	// Return the solution sequence
	return sequence;
}

uint16_t SliderSolver3x3::calcDistToSolution(const Slide_T & slide) const
{
	const PatternDatabase3x3 & database = *patternDatabase3x3Ptr;

	SliderBoard tempBoard(this->board);

	// 1-1.) Make the move
	tempBoard.slideSafe(slide);

	// 1-2.) Calculate the checksum of the move
	Checksum3x3 checksum(board);

	// 1-3.) See if we can find that checksum (or state) in the database
	PatternDatabase3x3::const_iterator databaseItr
		= database.find(std::move(Checksum3x3(tempBoard)));

	// Did we find a matching checksum?
	if (databaseItr == database.end()) {
		// No. This state must not be solvable
		cerr << __FILE__ << " line " << __LINE__
			<< " checksum was not found in database.\n";

		// Return MAX because this state is unsolvable
		return UINT16_MAX;
	}
	else {
		// Yes. We found it.

		// Return the distance to the solution 
		return (*databaseItr).second;
	}
}
