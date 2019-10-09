#pragma once

#include "PatternDatabase4x4.h"
#include "SliderSolver.h"

class SliderSolver4x4 : public SliderSolver
{
public:
	SliderSolver4x4() = delete;	// Don't create the default constructor
	SliderSolver4x4(const SliderBoard & board);
	~SliderSolver4x4();

	void setDatabasePtr(const PatternDatabase4x4 * patternDatabase4x4Ptr);

	virtual FastSlideSequence solve();

protected:
	uint16_t calcDistToSolution(const Slide_T & slide) const;

protected:
	const PatternDatabase4x4 * patternDatabase4x4Ptr = nullptr;
};

