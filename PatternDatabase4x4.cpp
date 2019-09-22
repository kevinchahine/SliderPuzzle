#include "PatternDatabase4x4.h"

using namespace std;

PatternDatabase4x4::PatternDatabase4x4()
{
}

PatternDatabase4x4::~PatternDatabase4x4()
{
}

void PatternDatabase4x4::writeToFile(std::ofstream & outFile) const
{
	// 1.) Checksums and Distances
	PatternDatabase4x4::const_iterator it;
	for (it = this->begin(); it != this->end(); it++) {
		// 1-0.) Get Node
		const pair<Checksum4x4, uint16_t> & node = *it;

		// 1-1.) Checksum 
		outFile << node.first.getChecksum() << ' ';

		// 1-2.) Distance to Solution 
		outFile << node.second << endl;
	}
}

void PatternDatabase4x4::readFromFile(std::ifstream & inFile)
{
	// 1.) Checksums and Distances
	// Make sure we didn't reach the end of the file
	while (!inFile.eof())
	{
		uint32_t checksum;
		uint16_t distance;

		inFile >> checksum;
		inFile >> distance;

		this->insert(pair<Checksum4x4, uint16_t>(Checksum4x4(checksum), distance));
	}
}
