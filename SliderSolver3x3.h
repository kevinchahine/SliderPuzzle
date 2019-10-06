#pragma once

#include "SliderSolver.h"

#include "Checksum3x3.h"
#include "PatternDatabase3x3.h"

class SliderSolver3x3 : public SliderSolver
{
public:
	SliderSolver3x3();
	~SliderSolver3x3();

	void setDatabasePtr(const PatternDatabase3x3 * patternDatabase3x3Ptr);

	virtual FastSlideSequence solve(const SliderBoard & board);

protected:
	const PatternDatabase3x3 * patternDatabase3x3Ptr;
};

