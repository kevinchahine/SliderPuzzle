#include "PatternDatabase3x3.h"

using namespace std;

PatternDatabase3x3::PatternDatabase3x3() {}

PatternDatabase3x3::~PatternDatabase3x3() {}

void PatternDatabase3x3::writeToFile(std::ofstream & outFile) const
{
	// 1.) Checksums (4 Bytes and Distances 2 Bytes)
	PatternDatabase3x3::const_iterator it;
	for (it = this->begin(); it != this->end(); it++) {
		// 1-0.) Get Node
		const pair<Checksum3x3, uint16_t> & node = *it;

		// 1-1.) Checksum (8 Bytes)
		outFile << node.first.getChecksum();

		// 1-2.) Distance to Solution (2 Bytes)
		outFile << node.second;
	}
}

void PatternDatabase3x3::readFromFile(std::ifstream & inFile)
{
	// 1.) Checksums (4 Bytes and Distances 2 Bytes)
	// Make sure we didn't reach the end of the file
	while (!inFile.eof())
	{
		uint32_t checksum;
		uint16_t distance;

		inFile >> checksum;
		inFile >> distance;

		this->insert(pair<Checksum3x3, uint16_t>(Checksum3x3(checksum), distance));
	}
}
