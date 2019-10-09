#include "FastSlideSequence.h"

#include <algorithm>

using namespace std;

FastSlideSequence::FastSlideSequence(size_t capacity) :
	SlideSequence<Slide_T>/*FastSlide_T>*/(capacity) {}

FastSlideSequence::~FastSlideSequence() {}

void FastSlideSequence::print(ostream & os) const
{
	size_t size = this->size();

	ios_base::fmtflags flags = os.flags();

	os << left;
	for_each(this->begin(), this->end(), [&](const Slide_T & nextSlide) {
		os << setw(6) << nextSlide;
		});

	os << '\n';

	os.flags(flags);
}
