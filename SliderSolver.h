#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

#include "SliderBoard.h"
#include "SlideSequence.h"
#include "FastSlideSequence.h"

class SliderSolver
{
public:
	SliderSolver();
	~SliderSolver();

	FastSlideSequence solve(const SliderBoard & board) = 0;

protected:

};

