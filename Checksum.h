#pragma once

#include <iostream>

#include "SliderBoard.h"

class Checksum
{
public:
	Checksum() {}
	Checksum(const Checksum & checksum) {}
	Checksum(const Checksum && checksum) noexcept {}
	~Checksum() {}

	/*virtual void setChecksum(uint64_t) = 0;

	virtual uint64_t getChecksum() const = 0;

	virtual void calcChecksum(const SliderBoard & board) = 0;

	virtual SliderBoard toSliderBoard() const = 0;

	virtual Checksum & operator=(const Checksum & checksum) = 0;
	virtual Checksum & operator=(Checksum && checksum) noexcept = 0;

	friend virtual std::ostream & operator<<(std::ostream & os, const Checksum & checksum) = 0;

	virtual bool operator<(const Checksum & right) const = 0;

	virtual bool operator==(const Checksum & right) const = 0;*/
};

//template<typename T>
//Checksum<T> & Checksum<T>::operator=(const Checksum<T> & checksum)
//{
//	this->checksumVal = checksum.checksumVal;
//
//	return (*this);
//}
//
//template<typename T>
//Checksum<T> & Checksum<T>::operator=(Checksum<T> && checksum) noexcept
//{
//	this->checksumVal = std::move(checksum.checksumVal);
//
//	return (*this);
//}
//
//template<typename T>
//std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum)
//{
//	os << checksum.checksumVal;
//
//	return os;
//}
//
//template<typename T>
//bool Checksum<T>::operator<(const Checksum & right) const
//{
//	return this->checksumVal < right.checksumVal;
//}
//
//template<typename T>
//bool Checksum<T>::operator==(const Checksum & right) const
//{
//	return this->checksumVal == right.checksumVal;
//}
