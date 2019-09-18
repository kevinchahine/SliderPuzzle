#pragma once

#include "SliderSolver.h"

class RandomSolver : public SliderSolver
{
public:
	RandomSolver();
	~RandomSolver();

	virtual FastSlideSequence solve(const SliderBoard & board);
};

