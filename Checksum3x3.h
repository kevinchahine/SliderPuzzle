#pragma once

#include "Checksum.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum3x3 : public Checksum<uint32_t>
{
public:
	Checksum3x3(uint32_t checksumVal);
	Checksum3x3(const SliderBoard & board);
	Checksum3x3(const Checksum3x3 & checksum3x3);
	Checksum3x3(Checksum3x3 && checksum3x3) noexcept;
	~Checksum3x3() {}

	virtual void calcChecksum(const SliderBoard & board);

	virtual SliderBoard toSliderBoard() const;
};

