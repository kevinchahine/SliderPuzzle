#pragma once

#include "Checksum.h"

template<typename T>
class ChecksumTemplate : public Checksum
{
public:
	ChecksumTemplate();
	ChecksumTemplate(uint64_t checksumVal);
	//virtual ChecksumTemplate(const SliderBoard & board) = 0;
	ChecksumTemplate(const ChecksumTemplate & checksum);
	ChecksumTemplate(ChecksumTemplate && checksum) noexcept;
	~ChecksumTemplate() {}

	/*irtual void setChecksum(uint64_t) = 0;

	virtual uint64_t getChecksum() const = 0;

	virtual void calcChecksum(const SliderBoard & board) = 0;

	virtual SliderBoard toSliderBoard() const = 0;

	virtual Checksum & operator=(const Checksum & checksum) = 0;
	virtual Checksum & operator=(Checksum && checksum) noexcept = 0;

	friend virtual std::ostream & operator<<(std::ostream & os, const Checksum & checksum) = 0;

	virtual bool operator<(const Checksum & right) const = 0;

	virtual bool operator==(const Checksum & right) const = 0;
*/
protected:
	T checksumVal = 0;
};

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate() :
	checksumVal(T()) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(uint64_t checksumVal) :
	checksumVal(checksumVal) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(const ChecksumTemplate & checksum) :
	checksumVal(checksum.checksumVal) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(ChecksumTemplate && checksum) noexcept :
	checksumVal(std::move(checksum.checksumVal)) {}

