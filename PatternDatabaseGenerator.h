#pragma once

#include "PatternDatabase.h"
#include "PatternDatabase3x3.h"
#include "PatternDatabase4x4.h"

class PatternDatabaseGenerator
{
public:
	PatternDatabaseGenerator();
	~PatternDatabaseGenerator();

	PatternDatabase3x3 generate3x3PatternDatabase() const;
	
	PatternDatabase4x4 generate4x4PatternDatabase(int distToSolLimit = INT_MAX) const;
};

