#pragma once

#include "PatternDatabase.h"

#include "Checksum4x4.h"

class PatternDatabase4x4 : public PatternDatabase<Checksum4x4>
{
public:
	/*PatternDatabase4x4();
	~PatternDatabase4x4();

	virtual void writeToFile(std::ofstream & outFile) const;

	virtual void readFromFile(std::ifstream & inFile);*/
};

