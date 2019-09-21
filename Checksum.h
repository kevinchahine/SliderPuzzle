#pragma once

#include <iostream>

// template type should only be unsigned integers
template<typename T>
class Checksum
{
public:
	Checksum() {}
	Checksum(T checksum) : checksum(checksum) {}
	~Checksum() {}

	T getChecksum() const;

	// No need for a setChecksum. That should only be set by calculating
	//	the checksum of a SliderBoard or by the Checksum constructor

	template<typename T>
	friend std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum);

protected:
	T checksum = 0;
};

template<typename T>
inline std::ostream & operator<<(std::ostream & os, const Checksum<T> & checksum)
{
	os << checksum.checksum;

	return os;
}

template<typename T>
inline T Checksum<T>::getChecksum() const
{
	return checksum;
}
