#pragma once

#include "SliderSolver.h"

#include "Checksum3x3.h"
#include "PatternDatabase3x3.h"

class SliderSolver3x3 : public SliderSolver
{
public:
	SliderSolver3x3() = delete;	// Don't create the default constructor
	SliderSolver3x3(const SliderBoard & board);
	~SliderSolver3x3();

	void setDatabasePtr(const PatternDatabase3x3 * patternDatabase3x3Ptr);

	virtual FastSlideSequence solve();

protected:
	uint16_t calcDistToSolution(const Slide_T & slide) const;

protected:
	const PatternDatabase3x3 * patternDatabase3x3Ptr = nullptr;
};

