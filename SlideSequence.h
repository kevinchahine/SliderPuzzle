#pragma once

#include "Slide.h"

#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
class SlideSequence : public std::vector<T>
{
public:
	SlideSequence(size_t capacity = 0);
	~SlideSequence();
};

template<typename T>
inline SlideSequence<T>::SlideSequence(size_t capacity)
{
	this->reserve(capacity);
}

template<typename T>
inline SlideSequence<T>::~SlideSequence()
{
}
