#pragma once

#include "Slide.h"

#include "SlideSequence.h"

class SafeSlideSequence : public SlideSequence<Slide_T> //SafeSlide_T>
{
public:
	SafeSlideSequence(size_t capacity = 0);
	~SafeSlideSequence();
};

