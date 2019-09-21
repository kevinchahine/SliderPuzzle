#pragma once

#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

#include "Coordinate.h"
#include "Matrix.h"
#include "SliderUtility.h"

extern std::default_random_engine generator;

class SliderBoard :	public Matrix<uint8_t>
{
public:
	SliderBoard();
	SliderBoard(size_t nRows, size_t nCols);
	//// Only works on 3x3 boards.
	//SliderBoard(size_t nRows, size_t nCols, uint32_t checksum3x3);
	//// Only works on 4x4 boards.
	//SliderBoard(size_t nRows, size_t nCols, uint64_t checksum4x4);
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

	void shuffle();

	void print(std::ostream & os = std::cout) const;

protected:
	Coordinate spaceCoordinate;
};

