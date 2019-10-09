#pragma once

#include <iostream>
#include <iomanip>
#include <time.h>

#include "SliderSolver.h"
#include "SliderSolver3x3.h"
#include "FastSlideSequence.h"

class SliderSolverDriver
{
public:
	int solve3x3(const PatternDatabase3x3 & database);
	
	// Lets you make moves manually while it calculates the distance to solution.
	int manualHillClimb3x3(const PatternDatabase3x3 & database);
};

