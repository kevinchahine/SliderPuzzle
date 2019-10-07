#include "FastSlideSequence.h"

FastSlideSequence::FastSlideSequence(size_t capacity) :
	SlideSequence<Slide_T>/*FastSlide_T>*/(capacity) {}

FastSlideSequence::~FastSlideSequence() {}
