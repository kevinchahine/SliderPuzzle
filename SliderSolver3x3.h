#pragma once

#include "SliderSolver.h"

class SliderSolver3x3 : public SliderSolver
{
public:
	SliderSolver3x3();
	~SliderSolver3x3();

	virtual FastSlideSequence solve(const SliderBoard & board);

};

