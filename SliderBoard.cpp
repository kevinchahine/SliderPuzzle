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

//SliderBoard::SliderBoard(size_t nRows, size_t nCols, uint32_t checksum) :
//	Matrix<uint8_t>(nRows, nCols),
//	spaceCoordinate(0, 0)
//{
//	init3x3Checksum(checksum);
//}
//
//SliderBoard::SliderBoard(size_t nRows, size_t nCols, uint64_t checksum) :
//	Matrix<uint8_t>(nRows, nCols),
//	spaceCoordinate(0, 0)
//{
//	init4x4Checksum(checksum);
//}

SliderBoard::SliderBoard(const SliderBoard & sliderBoard) :
	Matrix<uint8_t>(static_cast<Matrix<uint8_t>>(sliderBoard)),
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

uint32_t SliderBoard::calc32BitChecksum() const
{
	uint32_t checksum = 0;
	const size_t N_ELEMENTS = this->getNElements();

	for (size_t i = 0; i < N_ELEMENTS; i++) {
		checksum += this->at(i) * static_cast<uint32_t>(pow(N_ELEMENTS, i));
	}

	return checksum;
}

uint64_t SliderBoard::calc64BitChecksum() const
{
	uint64_t checksum = 0;
	const size_t N_ELEMENTS = this->getNElements();

	for (size_t i = 0; i < N_ELEMENTS; i++) {
		checksum += this->at(i) * static_cast<uint64_t>(pow(N_ELEMENTS, i));
	}

	return checksum;
}

void SliderBoard::init3x3Checksum(uint32_t checksum3x3)
{
	const int N_ELEMENTS = this->getNElements();

	register uint32_t tempA;
	register uint32_t tempB;

	for (int i = 0; i < N_ELEMENTS; i++)
	{
		tempA =
			static_cast<uint32_t>(shift(checksum3x3, N_ELEMENTS, -i));
		tempB =
			static_cast<uint32_t>(shift(checksum3x3, N_ELEMENTS, -(i + 1))) * N_ELEMENTS;

		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(tempA - tempB);
	}
}

void SliderBoard::init4x4Checksum(uint64_t checksum4x4)
{
//	const int N_ELEMENTS = this->getNElements();
//
//	register uint64_t tempA;
//	register uint64_t tempB;
//
//	for (int i = 0; i < N_ELEMENTS; i++)
//	{
//		double p = pow(N_ELEMENTS, i);
//		
//
//
//		/*tempA =
//			static_cast<uint64_t>(checksum4x4 >> -ishift(checksum, N_ELEMENTS, -i));
//		tempB =
//			static_cast<uint64_t>(shift(checksum, N_ELEMENTS, -(i + 1))) * N_ELEMENTS;
//
//		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(tempA - tempB);*/
//	}
}
