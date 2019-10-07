#include "SafeSlideSequence.h"

SafeSlideSequence::SafeSlideSequence(size_t capacity) :
	SlideSequence<Slide_T/*SafeSlide_T*/>(capacity) {}

SafeSlideSequence::~SafeSlideSequence() {}