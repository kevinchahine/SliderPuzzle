#pragma once

#include "Checksum.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum4x4 : public Checksum<uint64_t>
{
public:
	Checksum4x4(uint64_t checksum);
	Checksum4x4(const SliderBoard & board);
	~Checksum4x4() {}
	
	void setChecksum(const SliderBoard & board);

	void calcSliderBoard(SliderBoard & board) const;
};

