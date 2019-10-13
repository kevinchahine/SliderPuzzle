#pragma once

#include <iostream>

#include "SliderBoard.h"

class SliderBoard;

class Checksum
{
public:
	Checksum() {}
	Checksum(const Checksum & checksum) {}
	Checksum(const Checksum && checksum) noexcept {}
	~Checksum() {}

	virtual void setChecksumValue(uint64_t checksumValue) = 0;

	virtual uint64_t getChecksumValue() const = 0;

	virtual void calcChecksum(const SliderBoard & board) = 0;

	virtual SliderBoard toSliderBoard() const = 0;

	virtual Checksum & operator=(const Checksum & checksum) = 0;
	
	virtual Checksum & operator=(Checksum && checksum) noexcept = 0;

	friend std::ostream & operator<<(std::ostream & os, const Checksum & checksum);

	virtual bool operator<(const Checksum & right) const = 0;

	virtual bool operator==(const Checksum & right) const = 0;
};
