#include "PatternDatabase3x3.h"

using namespace std;

PatternDatabase3x3::PatternDatabase3x3() {}

PatternDatabase3x3::~PatternDatabase3x3() {}

void PatternDatabase3x3::writeToFile(std::ofstream & outFile) const
{
	// 1.) Checksums and Distances
	PatternDatabase3x3::const_iterator it;
	for (it = this->begin(); it != this->end(); it++) {
		// 1-0.) Get Node
		const pair<Checksum3x3, uint16_t> & node = *it;

		// 1-1.) Checksum 
		outFile << node.first.getChecksumValue() << ' ';

		// 1-2.) Distance to Solution
		outFile << node.second << endl;
	}
}

void PatternDatabase3x3::readFromFile(std::ifstream & inFile)
{
	// 1.) Checksums and Distances
	// Make sure we didn't reach the end of the file
	while (!inFile.eof())
	{
		uint32_t checksumVal;
		uint16_t distance;

		inFile >> checksumVal;
		inFile >> distance;

		this->insert(pair<Checksum3x3, uint16_t>(Checksum3x3(checksumVal), distance));
	}
}
