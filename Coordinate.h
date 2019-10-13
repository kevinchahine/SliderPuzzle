#pragma once

#include <iostream>
#include <tuple>

class Coordinate : protected std::pair<size_t, size_t>
{
public:
	Coordinate(size_t row, size_t col);
	Coordinate(const Coordinate & coord);
	Coordinate(Coordinate && coord) noexcept;
	~Coordinate() {}

	Coordinate & operator=(const Coordinate & coord)
	{
		this->first = coord.first;
		this->second = coord.second;
		
		return *this;
	}
	
	Coordinate & operator=(Coordinate && coord) noexcept
	{
		this->first = coord.first;
		this->second = coord.second;
		
		return *this;
	}
	
	friend std::ostream & operator<<(std::ostream & os, const Coordinate & coordinate);

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

