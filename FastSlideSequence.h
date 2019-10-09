#pragma once

#include <iostream>

#include "SlideSequence.h"

class FastSlideSequence : public SlideSequence<Slide_T>//FastSlide_T>
{
public:
	FastSlideSequence(size_t capacity = 0);
	~FastSlideSequence();

	void print(std::ostream & os = std::cout) const;
};

