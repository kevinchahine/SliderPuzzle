#pragma once

#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

#include "Coordinate.h"
#include "Matrix.h"
#include "SliderUtility.h"
#include "Slide.h"

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
	//SliderBoard(const SliderBoard && sliderBoard);
	~SliderBoard();

	void assign(const SliderBoard & board);

	// The position of the empty slot (or zero slot) is maintained internally
	// to promote efficiency is methods involving sliding and validating slides.
	// If the position of the empty slot is inaccurate, then unexpected results
	// may occur. 
	void alignPositionOfEmptySlot();

	// The position of the empty slot (or zero slot) is maintained internally
	// to promote efficiency is methods involving sliding and validating slides.
	// If the position of the empty slot is inaccurate, then unexpected results
	// may occur. Giving an accurate hint of where the empty slot is is not 
	// necessary but increases the speed of this method.
	void alignPositionOfEmptySlot(const Coordinate & emptySlotPosHint);

	// Returns true iff the tiles of the board are in ascending order from 
	//	left to right, up to down with zero in the lower 
	//	ex: 0 1 2
	//		3 4 5
	//		6 7 8
	bool isSolved() const;

	bool isSlideUpValid() const;
	bool isSlideDownValid() const;
	bool isSlideLeftValid() const;
	bool isSlideRightValid() const;
	//bool isSlideValid() const;

	bool slideUpSafe();
	bool slideDownSafe();
	bool slideLeftSafe();
	bool slideRightSafe();
	bool slideSafe(Slide_T slide);

	inline void slideUpFast();
	inline void slideDownFast();
	inline void slideLeftFast();
	inline void slideRightFast();
	void slideFast(Slide_T slide);

	void shuffle();

	void print(std::ostream & os = std::cout) const;

	SliderBoard & operator=(SliderBoard & board);

protected:
	Coordinate posOfEmptySlot;
};

