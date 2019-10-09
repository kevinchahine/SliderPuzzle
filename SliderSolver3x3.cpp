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

		// Return an empty solution sequence
		return FastSlideSequence();
	}

	// Does the data base contain anything?
	if (patternDatabase3x3Ptr->empty() == true) {
		cerr << "error: " << __FILE__ << " line " << __LINE__
			<< " database is empty\n";

		// Return an empty solution sequence
		return FastSlideSequence();
	}

	// Now we know that we have a non-empty database.
	const PatternDatabase3x3 & database = *patternDatabase3x3Ptr;

	// Can this board even be solved? 
	// The database contains all the states that are reachable from shuffling a 
	// solved board. If a state is not in this database, then the board cannot 
	// be solved. This could happen if the pieces on the board where placed 
	// randomly (and not shuffled by making valid moves) or this board is part 
	// of a larger board that is only partially solved.

	// Declare the solution sequence. This will keep track of all the moves that 
	// we make to solve the board.
	// Reserve enough space in the SliderSequence for 32 slides.
	// The longest a 3x3 slider puzzle should take to solve is 32 slides.
	FastSlideSequence sequence(32);
	
	// Run through hill climb algorithm until we reach the solution.
	while (!board.isSolved())
	{
		// -------- Analyze future moves --------
		// Try every valid move, and see which one brings us closer to the 
		// solution.
		uint16_t minDist = UINT16_MAX;
		Slide_T minMove = Slide_T::NONE;

		// --- UP ---
		if (board.isSlideUpValid() == true)
		{
			board.slideUpFast();

			// If we move UP, how far would we be from solution?
			uint16_t temp = database.find(Checksum3x3(board))->second;

			// Is that the best so far?
			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::UP;
			}

			board.slideDownFast();
		}

		// --- DOWN ---
		if (board.isSlideDownValid() == true)
		{
			board.slideDownFast();

			// If we move DOWN, how far would we be from solution.
			uint16_t temp = database.find(Checksum3x3(board))->second;

			// Is that the best so far
			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::DOWN;
			}

			board.slideUpFast();
		}

		// --- LEFT ---
		if (board.isSlideLeftValid() == true)
		{
			board.slideLeftFast();

			// If we move LEFT, how far would we be from solution.
			uint16_t temp = database.find(Checksum3x3(board))->second;

			// Is that the best so far
			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::LEFT;
			}

			board.slideRightFast();
		}

		// --- RIGHT ---
		if (board.isSlideRightValid() == true)
		{
			board.slideRightFast();
			
			// If we move RIGHT, how far would we be from solution.
			uint16_t temp = database.find(Checksum3x3(board))->second;

			// Is that the best so far
			if (temp < minDist) {
				minDist = temp;
				minMove = Slide_T::RIGHT;
			}

			board.slideLeftFast();
		}

		// Now we know what the next best move is (minMove).

		// Keep track of the slide in the solution sequence
		sequence.push_back(minMove);

		// Apply the move
		board.slideSafe(minMove);
	}

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
