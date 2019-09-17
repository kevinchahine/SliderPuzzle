#pragma once

#include <tuple>

class Coordinate : protected std::pair<size_t, size_t>
{
public:
	Coordinate(size_t row, size_t col) : std::pair<size_t, size_t>(row, col) {}
	~Coordinate() {}

	size_t & row()
	{
		return this->first;
	}
	
	const size_t & row() const
	{
		return this->first;
	}

	size_t & col()
	{
		return this->second;
	}

	const size_t & col() const
	{
		return this->second;
	}
};

