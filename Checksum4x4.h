#pragma once

#include "Checksum.h"

#include "SliderBoard.h"

class SliderBoard;

class Checksum4x4 : public Checksum<uint64_t>
{
public:
	Checksum4x4(uint64_t checksum);
	Checksum4x4(const Checksum4x4 & checksum4x4);
	Checksum4x4(const Checksum4x4 && checksum4x4) noexcept;
	Checksum4x4(const SliderBoard & board);
	~Checksum4x4() {}
	
	void setChecksum(const SliderBoard & board);

	SliderBoard toSliderBoard() const;

	bool operator<(const Checksum4x4 & right) const;

	bool operator==(const Checksum4x4 & right) const;
};

