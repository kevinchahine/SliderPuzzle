#pragma once

#include "SlideSequence.h"

class FastSlideSequence : public SlideSequence<FastSlide_T>
{
public:
	FastSlideSequence(size_t capacity = 0);
	~FastSlideSequence();
};

