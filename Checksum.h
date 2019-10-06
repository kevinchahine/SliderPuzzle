#pragma once

#include <iostream>

// template type should only be unsigned integers
template<typename T>
class Checksum
{
public:
	Checksum() {}
	Checksum(T checksum) : checksum(checksum) {}
	Checksum(const Checksum & checksum) : checksum(checksum.checksum) {}
	Checksum(const Checksum && checksum) noexcept : checksum(std::move(checksum.checksum)) {}
	~Checksum() {}

	Checksum<T> & operator=(const Checksum<T> & checksum);
	Checksum<T> & operator=(Checksum<T> && checksum) noexcept;

	T getChecksum() const;

	// No need for a setChecksum. That should only be set by calculating
	//	the checksum of a SliderBoard or by the Checksum constructor

	template<typename T>
	friend std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum);

protected:
	T checksum = 0;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum)
{
	os << checksum.checksum;

	return os;
}

template<typename T>
Checksum<T> & Checksum<T>::operator=(const Checksum<T> & checksum)
{
	this->checksum = checksum.checksum;

	return (*this);
}

template<typename T>
Checksum<T> & Checksum<T>::operator=(Checksum<T> && checksum) noexcept
{
	this->checksum = std::move(checksum.checksum);

	return (*this);
}

template<typename T>
inline T Checksum<T>::getChecksum() const
{
	return checksum;
}
