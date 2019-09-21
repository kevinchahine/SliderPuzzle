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
	SliderBoard(size_t nRows, size_t nCols, uint32_t checksum);
	SliderBoard(size_t nRows, size_t nCols, uint64_t checksum);
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

	uint32_t calc32BitChecksum() const;
	uint64_t calc64BitChecksum() const;

protected:
	// Initializes the elements of the slider board
	// based on the value of the checksum
	// WARNING: Not valid for sliderboards of size 4x4 or larger
	void initBy32BitChecksum(uint32_t checksum);

	// Initializes the elements of the slider board
	// based on the value of the checksum
	// WARNING: Not valid for sliderboards larger than 4x4 
	void initBy64BitChecksum(uint64_t checksum);

protected:
	Coordinate spaceCoordinate;
};

