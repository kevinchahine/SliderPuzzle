#include "SliderBoard.h"

#include <math.h>
#include <utility>

using namespace std;

SliderBoard::SliderBoard() :
	Matrix<uint8_t>(3, 3),
	posOfEmptySlot(0, 0)
{
	for (size_t i = 0; i < this->getNElements(); i++)
	{
		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(i);
	}
}

SliderBoard::SliderBoard(size_t nRows, size_t nCols) :
	Matrix<uint8_t>(nRows, nCols),
	posOfEmptySlot(0, 0) 
{
	for (size_t i = 0; i < this->getNElements(); i++) 
	{
		this->std::vector<uint8_t>::at(i) = static_cast<uint8_t>(i);
	}
}

SliderBoard::SliderBoard(const SliderBoard & sliderBoard) :
	Matrix<uint8_t>(static_cast<Matrix<uint8_t>>(sliderBoard)),
	posOfEmptySlot(sliderBoard.posOfEmptySlot) 
{}

SliderBoard::~SliderBoard() {}

void SliderBoard::assign(const SliderBoard & board)
{
	this->Matrix<uint8_t>::assign(board);

	this->posOfEmptySlot = board.posOfEmptySlot;
}

void SliderBoard::alignPositionOfEmptySlot()
{
	// 1.) Find location of the empty (or zero slot)
	Matrix<uint8_t>::const_iterator emptySlotItr = 
		find(this->begin(), this->end(), 0);

	// 2.) Did we find the empty slot or is it missing?
	if (emptySlotItr == this->end()) {
		// No we didn't.
#if _DEBUG
		cerr << __FILE__ << " line " << __LINE__
			<< "empty slot not found\n";
		return;
	}
#endif
	
	// 3.) align position of empty slot;
	size_t emptyPos = *emptySlotItr;

	this->posOfEmptySlot = Coordinate(rowCoord(emptyPos), colCoord(emptyPos));
}

void SliderBoard::alignPositionOfEmptySlot(const Coordinate & emptySlotPosHint)
{
	// Is the hint accurate?
	if (this->at(emptySlotPosHint) == 0) {
		// Yes. No need to search for it.
		this->posOfEmptySlot = emptySlotPosHint;
	}
	else {
		// No. We need to align the empty slot ourselves.
		alignPositionOfEmptySlot();
	}
}

bool SliderBoard::isSolved() const
{
	// Iterate through the board tile by tile
	for (size_t i = 0; i < this->getNElements(); i++) {
		// If the tile has the same value as the index,
		// Then that tile is in the correct place.
		if (this->at(i) != i) {
			// We found a missed placed tile
			return false;
		}
	}

	return true;
}

bool SliderBoard::isSlideUpValid() const
{
	return this->posOfEmptySlot.row() > 0;
}

bool SliderBoard::isSlideDownValid() const
{
	return this->posOfEmptySlot.row() < (getNRows() - 1);
}

bool SliderBoard::isSlideLeftValid() const
{
	return this->posOfEmptySlot.col() > 0;
}

bool SliderBoard::isSlideRightValid() const
{
	return this->posOfEmptySlot.col() < (getNCols() - 1);
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

bool SliderBoard::slideSafe(Slide_T slide)
{
	switch (slide)
	{
	case Slide_T::UP:		return slideUpSafe();	
	case Slide_T::DOWN:		return slideDownSafe();
	case Slide_T::LEFT:		return slideLeftSafe();
	case Slide_T::RIGHT:	return slideRightSafe();
	default:
		cerr << "error: " << __FILE__ << " line " << __LINE__
			<< " default case triggered slide = "
			<< static_cast<char>(slide) << '\n';
		
		return false;
	}
}

void SliderBoard::slideUpFast()
{
	size_t col = posOfEmptySlot.col();
	size_t row = posOfEmptySlot.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row - 1, col);

	std::swap(a, b);

	posOfEmptySlot.row()--;
	;
}

void SliderBoard::slideDownFast()
{
	size_t col = posOfEmptySlot.col();
	size_t row = posOfEmptySlot.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row + 1, col);

	std::swap(a, b);
	
	posOfEmptySlot.row()++;
	;
}

void SliderBoard::slideLeftFast()
{
	size_t col = posOfEmptySlot.col();
	size_t row = posOfEmptySlot.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row, col - 1);

	std::swap(a, b);
	
	posOfEmptySlot.col()--;
	;
}

void SliderBoard::slideRightFast()
{
	size_t col = posOfEmptySlot.col();
	size_t row = posOfEmptySlot.row();
	uint8_t & a = at(row, col);
	uint8_t & b = at(row, col + 1);

	std::swap(a, b);

	posOfEmptySlot.col()++;
	;
}

void SliderBoard::slideFast(Slide_T slide)
{
	switch (slide)
	{
	case Slide_T::UP:		return slideUpFast();
	case Slide_T::DOWN:		return slideDownFast();
	case Slide_T::LEFT:		return slideLeftFast();
	case Slide_T::RIGHT:	return slideRightFast();
	}
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
		if (r == nRows - 1)
			os << '\t' << posOfEmptySlot;

		os << '\n';
	}
	
	os << '\n';
}

SliderBoard & SliderBoard::operator=(SliderBoard & board)
{
	this->assign(board);

	return *this;
}

