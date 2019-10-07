#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

#include "Slide.h"
#include "SliderBoard.h"
#include "SlideSequence.h"
#include "FastSlideSequence.h"

class SliderSolver
{
public:
	SliderSolver(const SliderBoard & board);
	~SliderSolver();

	virtual FastSlideSequence solve() = 0;

protected:
	SliderBoard board;
};

