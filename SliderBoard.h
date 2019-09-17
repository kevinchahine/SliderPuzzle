#pragma once

#include <iostream>
#include <iomanip>

#include "Coordinate.h"
#include "Matrix.h"

class SliderBoard :	public Matrix<uint16_t>
{
public:
	SliderBoard();
	SliderBoard(size_t nRows, size_t nCols);
	SliderBoard(const SliderBoard & sliderBoard);
	SliderBoard(const SliderBoard && sliderBoard);
	~SliderBoard();

	bool isSlideUpValid() const;
	bool isSlideDownValid() const;
	bool isSlideLeftValid() const;
	bool isSlideRightValid() const;

	bool slideUpSafe();
	bool slideDownSafe();
	bool slideLeftSafe();
	bool slideRightSafe();

	inline void slideUpFast();
	inline void slideDownFast();
	inline void slideLeftFast();
	inline void slideRightFast();

	void print(std::ostream & os = std::cout) const;

protected:
	Coordinate spaceCoordinate;
};

