#pragma once

#include <iostream>
#include <fstream>

#include "PatternDatabase.h"

#include "Checksum3x3.h"

class PatternDatabase3x3 : public PatternDatabase<Checksum3x3>
{
public:
	PatternDatabase3x3();
	~PatternDatabase3x3();

	void writeToFile(std::ofstream & outFile) const;

	void readFromFile(std::ifstream & inFile);
};

