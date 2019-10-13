#include "Checksum.h"

std::ostream & operator<<(std::ostream & os, const Checksum & checksum)
{
	os << checksum.getChecksumValue();

	return os;
}
