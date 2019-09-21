#pragma once

#include <time.h>
#include <random>

#include "SliderBoard.h"

extern std::default_random_engine generator;

class SliderBoard;

void shuffle(SliderBoard & board, size_t count);

// Shifts the "digits" of a value of any base by dividing (or shifting)
// it by the base a given number of times.
// ex: To shift 54321 2 digits to the left into 543 in base 10 call
//		shift(54321, 10, -2);
//		All that this does is: 54321 / 10 / 10
//		or 54321 / 10 ^ 2 but without incurring overflow in the 
//		power operator.
// This is can alternative to using the pow function for very large numbers
// WARNING: It is recommended to only use this function template with 
//		integer based data types and not floating point.
template<typename T>
T shift(T value, uint32_t base, int32_t shift);

// ========================== DEFINITIONS =====================================

template<typename T>
T shift(T value, uint32_t base, int32_t shift)
{
	// If shift is negative, shift to the right (Hint: Divide by the base)
	if (shift < 0) {
		shift = abs(shift);

		for (int32_t i = 0; i < shift; i++) {
			value /= base;
		}
	}
	// If shift is not negative, shift to the left (Hint: Multiply by the base)
	else {
		for (int32_t i = 0; i < shift; i++) {
			value *= base;
		}
	}

	return value;
}