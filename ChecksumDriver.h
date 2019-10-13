#pragma once

#include "Checksum.h"
#include "Checksum3x3.h"
#include "Checksum4x4.h"

class ChecksumDriver
{
public:
	void testAll();

	void testAccessors();

	void testCalcChecksum();

	void testChecksumConstructors();

	void testChecksums();

	void test3x3Checksum();

	void test4x4Checksum();
};

