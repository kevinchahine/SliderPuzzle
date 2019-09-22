#include "PatternDatabaseDriver.h"

using namespace std;

void PatternDatabaseDriver::testReadWrite3x3()
{
	PatternDatabase3x3 database;
	PatternDatabase3x3 database2;

	ofstream outFile;
	ifstream inFile;

	for (uint32_t i = 0; i < 1000000; i++) {
		database.insert(pair<Checksum3x3, uint16_t>(Checksum3x3(i), static_cast<uint16_t>(i)));
	}

	outFile.open("database3x3.dat");
	database.writeToFile(outFile);

	inFile.open("database3x3.dat");
	database2.readFromFile(inFile);

	cout << database.size() << " " << database2.size() << '\n';
}

void PatternDatabaseDriver::testReadWrite4x4()
{
	PatternDatabase4x4 database;
	PatternDatabase4x4 database2;

	ofstream outFile;
	ifstream inFile;

	for (uint32_t i = 0; i < 1000; i++) {
		database.insert(pair<Checksum4x4, uint16_t>(Checksum4x4(i), static_cast<uint16_t>(i)));
	}

	outFile.open("database4x4.dat");
	database.writeToFile(outFile);

	inFile.open("database4x4.dat");
	database2.readFromFile(inFile);

	cout << database.size() << " " << database2.size() << '\n';
}
