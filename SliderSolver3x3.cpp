#include "SliderSolver3x3.h"

SliderSolver3x3::SliderSolver3x3()
{
}

SliderSolver3x3::~SliderSolver3x3()
{
}

FastSlideSequence SliderSolver3x3::solve(const SliderBoard & board)
{
	SliderBoard state(board);
	state.print();
	// Reserve enough space in the SliderSequence for 32 slides.
	// The longest a 3x3 slider puzzle should take to solve is 32 slides.
	FastSlideSequence sequence(32);

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
			state.slideUpFast();
			uint16_t temp = 
		}

		// 2.) Which one has the lowest distance to solution

		// 3.) Make that slide

		state.print();
		nIterations++;
	}

	return sequence;
}
