#include "Coordinate.h"

using namespace std;

Coordinate::Coordinate(size_t row, size_t col) : 
	pair<size_t, size_t>(row, col) 
{}

Coordinate::Coordinate(const Coordinate & coord) :
	pair<size_t, size_t>(coord)
{}

Coordinate::Coordinate(Coordinate && coord) noexcept :
	pair<size_t, size_t>(move(coord))
{}

Coordinate & Coordinate::operator=(const Coordinate & coord)
{
	static_cast<pair<size_t, size_t>>(*this) = coord;

	return (*this);
}

Coordinate & Coordinate::operator=(Coordinate && coord) noexcept
{
	static_cast<pair<size_t, size_t>>(*this) = move(coord);

	return (*this);
}

// REMOVE this
Coordinate Coordinate::toCoordinate()
{
	Coordinate c(3, 4);
	return c;
}
