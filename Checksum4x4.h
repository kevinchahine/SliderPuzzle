#pragma once

#include "Checksum.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum4x4 : public Checksum<uint64_t>
{
public:
	Checksum4x4(uint64_t checksumVal);
	Checksum4x4(const Checksum4x4 & checksum4x4);
	Checksum4x4(const Checksum4x4 && checksum4x4) noexcept;
	Checksum4x4(const SliderBoard & board);
	~Checksum4x4() {}
	
	virtual void calcChecksum(const SliderBoard & board);

	virtual SliderBoard toSliderBoard() const;
};

