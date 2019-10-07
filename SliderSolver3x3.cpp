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
	// else Yes, we have a database
	
	// Reserve enough space in the SliderSequence for 32 slides.
	// The longest a 3x3 slider puzzle should take to solve is 32 slides.
	FastSlideSequence sequence(32);

	// For testing only.
	// nIterations keeps track of how long our solver took to finish
	// Should take less than 33 iterations.
	int nIterations = 0;

	// Perform hill climb algorithm until solution is reached
	// Should not take more than 32 moves for 3x3 board
	while (!board.isSolved() && nIterations < 33) {
		// Stores the best movement (or slide) of the ones that
		// are valid
		Slide_T bestSlide = Slide_T::NONE;

		// Stores the distance to solution of the state bestSlide will
		// take us to.
		uint16_t bestSlideDist = UINT16_MAX;

		// 1.) What are our possible slides (aka moves)

		// 1-UP.) Analyze Slide UP
		if (board.isSlideUpValid()) {
			// 1-1.) If we where to  make this move what would the distance
			//		to the solution be.
			uint16_t tempDist = this->calcDistToSolution(Slide_T::UP);

			// 1-2.) Was this move better than the previous one
			if (tempDist < bestSlideDist) {
				// Yes. Slide UP is the best so far.
				bestSlide = Slide_T::UP;
				
				// Move down the benchmark
				bestSlideDist = tempDist;
			}
		}

		// 1-UP.) Analyze Slide DOWN
		if (board.isSlideDownValid()) {
			// 1-1.) If we where to  make this move what would the distance
			//		to the solution be.
			uint16_t tempDist = this->calcDistToSolution(Slide_T::DOWN);

			// 1-2.) Was this move better than the previous one
			if (tempDist < bestSlideDist) {
				// Yes. Slide UP is the best so far.
				bestSlide = Slide_T::DOWN;

				// Move down the benchmark
				bestSlideDist = tempDist;
			}
		}

		// 1-LEFT.) Analyze Slide LEFT
		if (board.isSlideUpValid()) {
			// 1-1.) If we where to  make this move what would the distance
			//		to the solution be.
			uint16_t tempDist = this->calcDistToSolution(Slide_T::LEFT);

			// 1-2.) Was this move better than the previous one
			if (tempDist < bestSlideDist) {
				// Yes. Slide UP is the best so far.
				bestSlide = Slide_T::LEFT;

				// Move down the benchmark
				bestSlideDist = tempDist;
			}
		}

		// 1-RIGHT.) Analyze Slide RIGHT
		if (board.isSlideUpValid()) {
			// 1-1.) If we where to  make this move what would the distance
			//		to the solution be.
			uint16_t tempDist = this->calcDistToSolution(Slide_T::RIGHT);

			// 1-2.) Was this move better than the previous one
			if (tempDist < bestSlideDist) {
				// Yes. Slide RIGHT is the best so far.
				bestSlide = Slide_T::RIGHT;

				// Move down the benchmark
				bestSlideDist = tempDist;
			}
		}

		// Now we know what the next best slide is.

		// 2.) Make that slide
		//if (this->board.slideSafe(bestSlide) == false)
		//{
		//	cerr << "Slide is not valid" << endl;
		//}
		board.slideSafe(bestSlide);

		// 3.) Push that slide to solution sequence
		sequence.push_back(bestSlide);
		
		cout << "Move " << bestSlide << '\n';
		board.print();
		cin.get();

		// 4.) Keep track of iterations incase we run into an infinite loop
		nIterations++;

		// And keep going till board is solved
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
