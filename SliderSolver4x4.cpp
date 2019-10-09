#include "SliderSolver4x4.h"

SliderSolver4x4::SliderSolver4x4(const SliderBoard & board) :
	SliderSolver(board) {}

SliderSolver4x4::~SliderSolver4x4() {}

void SliderSolver4x4::setDatabasePtr(const PatternDatabase4x4 * patternDatabase4x4Ptr)
{
	this->patternDatabase4x4Ptr = patternDatabase4x4Ptr;
}

FastSlideSequence SliderSolver4x4::solve()
{
	return FastSlideSequence();
}

uint16_t SliderSolver4x4::calcDistToSolution(const Slide_T & slide) const
{
	return uint16_t();
}
