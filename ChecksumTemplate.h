#pragma once

#include "Checksum.h"

template<typename T>
class ChecksumTemplate : public Checksum
{
public:
	ChecksumTemplate();
	ChecksumTemplate(uint64_t checksumVal);
	ChecksumTemplate(const ChecksumTemplate & checksum);
	ChecksumTemplate(ChecksumTemplate && checksum) noexcept;
	~ChecksumTemplate() {}

	virtual void setChecksumValue(uint64_t checksumValue);

	virtual uint64_t getChecksumValue() const;
	
	virtual void calcChecksum(const SliderBoard & board) = 0;

	virtual SliderBoard toSliderBoard() const = 0;

	virtual Checksum & operator=(const Checksum & checksum);
	
	virtual Checksum & operator=(Checksum && checksum) noexcept;

	template<typename T>
	friend std::ostream & operator<<(std::ostream & os, const ChecksumTemplate<T> & checksum);

	virtual bool operator<(const Checksum & right) const;

	virtual bool operator==(const Checksum & right) const;

protected:
	T checksumVal = 0;
};

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate() :
	checksumVal(T()) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(uint64_t checksumVal) :
	checksumVal(static_cast<T>(checksumVal)) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(const ChecksumTemplate & checksum) :
	checksumVal(checksum.checksumVal) {}

template<typename T>
inline ChecksumTemplate<T>::ChecksumTemplate(ChecksumTemplate && checksum) noexcept :
	checksumVal(std::move(checksum.checksumVal)) {}

template<typename T>
inline void ChecksumTemplate<T>::setChecksumValue(uint64_t checksumValue)
{
	this->checksumVal = static_cast<T>(checksumValue);
}

template<typename T>
inline uint64_t ChecksumTemplate<T>::getChecksumValue() const
{
	return static_cast<T>(this->checksumVal);
}

template<typename T>
inline Checksum & ChecksumTemplate<T>::operator=(const Checksum & checksum)
{
	this->checksumVal = static_cast<T>(checksum.getChecksumValue());

	return (*this);
}

template<typename T>
inline Checksum & ChecksumTemplate<T>::operator=(Checksum && checksum) noexcept
{
	this->checksumVal = static_cast<T>(checksum.getChecksumValue());

	return (*this);
}

template<typename T>
inline bool ChecksumTemplate<T>::operator<(const Checksum & right) const
{
	return this->checksumVal < right.getChecksumValue();
}

template<typename T>
inline bool ChecksumTemplate<T>::operator==(const Checksum & right) const
{
	return this->checksumVal == right.getChecksumValue();
}

template<typename T>
inline std::ostream & operator<<(std::ostream & os, const ChecksumTemplate<T> & checksum)
{
	os << checksum.checksumVal;

	return os;
}
