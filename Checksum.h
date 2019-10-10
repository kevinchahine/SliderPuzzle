#pragma once

#include <iostream>

#include "SliderBoard.h"

// template type should only be unsigned integers
template<typename T>
class Checksum
{
public:
	Checksum() {}
	Checksum(T checksumVal) : checksumVal(checksumVal) {}
	Checksum(const Checksum & checksum) : checksumVal(checksum.checksumVal) {}
	Checksum(const Checksum && checksum) noexcept : checksumVal(std::move(checksum.checksumVal)) {}
	~Checksum() {}

	T getChecksum() const;

	virtual void calcChecksum(const SliderBoard & board) = 0;

	virtual SliderBoard toSliderBoard() const = 0;

	Checksum<T> & operator=(const Checksum<T> & checksum);
	Checksum<T> & operator=(Checksum<T> && checksum) noexcept;

	template<typename T>
	friend std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum);

	bool operator<(const Checksum & right) const;

	bool operator==(const Checksum & right) const;

protected:
	T checksumVal = 0;
};

template<typename T>
inline T Checksum<T>::getChecksum() const
{
	return checksumVal;
}

template<typename T>
Checksum<T> & Checksum<T>::operator=(const Checksum<T> & checksum)
{
	this->checksumVal = checksum.checksumVal;

	return (*this);
}

template<typename T>
Checksum<T> & Checksum<T>::operator=(Checksum<T> && checksum) noexcept
{
	this->checksumVal = std::move(checksum.checksumVal);

	return (*this);
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum)
{
	os << checksum.checksumVal;

	return os;
}

template<typename T>
bool Checksum<T>::operator<(const Checksum & right) const
{
	return this->checksumVal < right.checksumVal;
}

template<typename T>
bool Checksum<T>::operator==(const Checksum & right) const
{
	return this->checksumVal == right.checksumVal;
}
