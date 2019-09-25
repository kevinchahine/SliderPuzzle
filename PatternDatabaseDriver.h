#pragma once

#include "PatternDatabase.h"
#include "PatternDatabase4x4.h"
#include "PatternDatabase3x3.h"

extern std::string database3x3FileName;
extern std::string database4x4FileName;

class PatternDatabaseDriver
{
public:
	void testReadWrite3x3();

	void testReadWrite4x4();

	void testDistanceToSolution3x3(const PatternDatabase3x3 & database);
};

