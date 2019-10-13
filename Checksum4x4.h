#pragma once

#include "ChecksumTemplate.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum4x4 : public ChecksumTemplate<uint64_t>
{
public:
	Checksum4x4(uint64_t checksum) :
		ChecksumTemplate<uint64_t>(checksum) {}
	Checksum4x4(const Checksum4x4 & checksum) :
		ChecksumTemplate<uint64_t>(checksum) {}
	Checksum4x4(const Checksum4x4 && checksum) noexcept :
		ChecksumTemplate<uint64_t>(std::move(checksum)) {}
	Checksum4x4(const SliderBoard & board)
	{
		calcChecksum(board);
	}
	~Checksum4x4() {}
	
	virtual void calcChecksum(const SliderBoard & board);

	virtual SliderBoard toSliderBoard() const;

};

