#include "SliderSolver3x3.h"

using namespace std;

SliderSolver3x3::SliderSolver3x3() :
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

FastSlideSequence SliderSolver3x3::solve(const SliderBoard & board)
{
	if (patternDatabase3x3Ptr == nullptr) {
		cerr << __FILE__ << " line " << __LINE__
			<< " patternDatabase3x3Ptr = nullptr\n";
		return FastSlideSequence();
	}

	const PatternDatabase3x3 & database = *patternDatabase3x3Ptr;

	SliderBoard state(board);
	state.print();

	// Reserve enough space in the SliderSequence for 32 slides.
	// The longest a 3x3 slider puzzle should take to solve is 32 slides.
	FastSlideSequence sequence(32);

	PatternDatabase3x3::const_iterator databaseItr;

	int nIterations = 0;

	// Perform hill climb algorithm until solution is reached
	// Should not take more than 32 moves for 3x3 board
	while (!state.isSolved() && nIterations < 33) {
		// Temporarily stores the best movement (or slide) of the ones that
		// are valid
		FastSlide_T bestSlide = nullptr;

		// Temporarily stores the distance to solution of the state bestSlide will
		// take us to.
		uint16_t bestSlideDist = UINT16_MAX;

		// 1.) What are our possible slides (aka moves)
		if (state.isSlideUpValid()) {
			// 1-1.) Make the move
			state.slideUpFast();
			
			// 1-2.) Calculate the checksum of the move
			Checksum3x3 checksum(state);

			// 1-3.) See if we can find that checksum (or state) in the database
			databaseItr = database.find(checksum.getChecksum());

			// Did we find a matching checksum?
			if (databaseItr == database.end()) {
				// No. 
				cerr << __FILE__ << " line " << __LINE__
					<< " checksum was not found in database.\n";

				// Return the solution so far
				return sequence;
			}

			// 1-4.) Did we find an even better slide (or move)
			if (databaseItr->second < bestSlideDist) {
				// Yes. 
				///bestSlide = SliderBoard::slideUpFast;
			}
		}

		// 2.) Which one has the lowest distance to solution

		// 3.) Make that slide

		state.print();
		nIterations++;
	}

	return sequence;
}
