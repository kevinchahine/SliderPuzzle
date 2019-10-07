#pragma once

#include "SliderSolver.h"
#include "SliderSolver3x3.h"
#include "FastSlideSequence.h"

class SliderSolverDriver
{
public:

	int solve3x3(const PatternDatabase3x3 & database);
};

