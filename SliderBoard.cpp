#include "SliderBoard.h"

#include <utility>

using namespace std;

SliderBoard::SliderBoard() :
	Matrix<uint16_t>(3, 3),
	spaceCoordinate(0, 0)
{
	for (size_t i = 0; i < this->getNElements(); i++)
	{
		this->std::vector<uint16_t>::at(i) = static_cast<uint16_t>(i);
	}
}

SliderBoard::SliderBoard(size_t nRows, size_t nCols) :
	Matrix<uint16_t>(nRows, nCols),
	spaceCoordinate(0, 0) 
{
	for (size_t i = 0; i < this->getNElements(); i++) 
	{
		this->std::vector<uint16_t>::at(i) = static_cast<uint16_t>(i);
	}
}

SliderBoard::SliderBoard(const SliderBoard & sliderBoard) :
	Matrix<uint16_t>(static_cast<Matrix<uint16_t>>(sliderBoard)),
	spaceCoordinate(sliderBoard.spaceCoordinate) 
{}

SliderBoard::~SliderBoard() {}

bool SliderBoard::isSlideUpValid() const
{
	return this->spaceCoordinate.row() > 0;
}

bool SliderBoard::isSlideDownValid() const
{
	return this->spaceCoordinate.row() < (getNRows() - 1);
}

bool SliderBoard::isSlideLeftValid() const
{
	return this->spaceCoordinate.col() > 0;
}

bool SliderBoard::isSlideRightValid() const
{
	return this->spaceCoordinate.col() < (getNCols() - 1);
}

bool SliderBoard::slideUpSafe()
{
	if (isSlideUpValid() == true)
	{
		slideUpFast();
		return true;
	}
	else {
		return false;
	}
}

bool SliderBoard::slideDownSafe()
{
	if (isSlideDownValid() == true)
	{
		slideDownFast();
		return true;
	}
	else {
		return false;
	}
}

bool SliderBoard::slideLeftSafe()
{
	if (isSlideLeftValid() == true)
	{
		slideLeftFast();
		return true;
	}
	else {
		return false;
	}
}

bool SliderBoard::slideRightSafe()
{
	if (isSlideRightValid() == true)
	{
		slideRightFast();
		return true;
	}
	else {
		return false;
	}
}

void SliderBoard::slideUpFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint16_t & a = at(row, col);
	uint16_t & b = at(row - 1, col);

	uint16_t temp = a;
	a = b;
	b = temp;

	spaceCoordinate.row()--;
}

void SliderBoard::slideDownFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint16_t & a = at(row, col);
	uint16_t & b = at(row + 1, col);

	uint16_t temp = a;
	a = b;
	b = temp; spaceCoordinate.row()++;
}

void SliderBoard::slideLeftFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint16_t & a = at(row, col);
	uint16_t & b = at(row, col - 1);

	uint16_t temp = a;
	a = b;
	b = temp; 
	
	spaceCoordinate.col()--;
}

void SliderBoard::slideRightFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint16_t & a = at(row, col);
	uint16_t & b = at(row, col + 1);

	uint16_t temp = a;
	a = b;
	b = temp;

	spaceCoordinate.col()++;
}

void SliderBoard::print(std::ostream & os) const
{
	// Use this for now. Later make a more appealing print function
	this->Matrix<uint16_t>::print(os);
}

