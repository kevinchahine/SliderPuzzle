#pragma once

#include <iostream>

template<typename T>
class Checksum
{
public:
	Checksum() {}
	Checksum(T) {}
	~Checksum() {}

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
