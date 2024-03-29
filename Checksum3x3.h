#pragma once

#include "ChecksumTemplate.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum3x3 : public ChecksumTemplate<uint32_t>
{
public:
	Checksum3x3() = delete;
	Checksum3x3(uint32_t checksumVal) :
		ChecksumTemplate<uint32_t>(checksumVal) {}
	Checksum3x3(const Checksum3x3 & checksum3x3) :
		ChecksumTemplate<uint32_t>(checksum3x3) {}
	Checksum3x3(Checksum3x3 && checksum3x3) noexcept :
		ChecksumTemplate(std::move(checksum3x3)) {}
	Checksum3x3(const SliderBoard & board)
	{
		calcChecksum(board);
	}

	~Checksum3x3() {}

	virtual void calcChecksum(const SliderBoard & board);

	virtual SliderBoard toSliderBoard() const;

};
