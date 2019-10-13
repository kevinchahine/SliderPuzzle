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

std::ostream & operator<<(std::ostream & os, const Coordinate & coordinate)
{
	os << '(' << coordinate.row() << ", " << coordinate.col() << ')';

	return os;
}
