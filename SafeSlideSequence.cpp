#include "SafeSlideSequence.h"

SafeSlideSequence::SafeSlideSequence(size_t capacity) :
	SlideSequence<SafeSlide_T>(capacity) {}

SafeSlideSequence::~SafeSlideSequence() {}