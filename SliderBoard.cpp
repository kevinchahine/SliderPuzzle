#include "SliderBoard.h"

#include <math.h>
#include <utility>

using namespace std;

SliderBoard::SliderBoard() :
	Matrix<uint8_t>(3, 3),
	spaceCoordinate(0, 0)
{
	for (size_t i = 0; i < this->getNElements(); i++)
	{
		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(i);
	}
}

SliderBoard::SliderBoard(size_t nRows, size_t nCols) :
	Matrix<uint8_t>(nRows, nCols),
	spaceCoordinate(0, 0) 
{
	for (size_t i = 0; i < this->getNElements(); i++) 
	{
		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(i);
	}
}

SliderBoard::SliderBoard(const SliderBoard & sliderBoard) :
	Matrix<uint8_t>(static_cast<Matrix<uint8_t>>(sliderBoard)),
	spaceCoordinate(sliderBoard.spaceCoordinate) 
{}

SliderBoard::~SliderBoard() {}

void SliderBoard::assign(const SliderBoard & board)
{
	this->Matrix<uint8_t>::assign(board);

	this->spaceCoordinate = board.spaceCoordinate;
}

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
	uint8_t & a = at(row, col);
	uint8_t & b = at(row - 1, col);

	uint8_t temp = a;
	a = b;
	b = temp;

	spaceCoordinate.row()--;
}

void SliderBoard::slideDownFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row + 1, col);

	uint8_t temp = a;
	a = b;
	b = temp; spaceCoordinate.row()++;
}

void SliderBoard::slideLeftFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row, col - 1);

	uint8_t temp = a;
	a = b;
	b = temp; 
	
	spaceCoordinate.col()--;
}

void SliderBoard::slideRightFast()
{
	size_t col = spaceCoordinate.col();
	size_t row = spaceCoordinate.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row, col + 1);

	uint8_t temp = a;
	a = b;
	b = temp;

	spaceCoordinate.col()++;
}

void SliderBoard::shuffle()
{
	uniform_int_distribution<int> dist(0, 3);
	size_t count = getNElements() * getNElements();

	for (size_t i = 0; i < count; i++) {
		int move = dist(generator);

		switch (move)
		{
		case 0:	// UP
			this->slideUpSafe();
			break;
		case 1: // DOWN
			this->slideDownSafe();
			break;
		case 2: // LEFT
			this->slideLeftSafe();
			break;
		case 3:	// RIGHT
			this->slideRightSafe();
			break;
		}
	}
}

void SliderBoard::print(std::ostream & os) const
{
	// Use this for now. Later make a more appealing print function
	for (size_t r = 0; r < nRows; r++) {
		for (size_t c = 0; c < nCols; c++) {
			os << std::setw(6) << static_cast<int>(at(r, c));
		}
		os << '\n';
	}
	os << '\n';
}

SliderBoard & SliderBoard::operator=(SliderBoard & board)
{
	this->assign(board);

	return *this;
}

