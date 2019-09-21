#pragma once

#include "Checksum.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum3x3 : public Checksum<uint64_t>
{
public:
	Checksum3x3(const SliderBoard & board);
	~Checksum3x3() {}

	void setChecksum(const SliderBoard & board);

	void calcSliderBoard(SliderBoard & board) const;
};

