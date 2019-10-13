#include "PatternDatabaseDriver.h"

using namespace std;

void PatternDatabaseDriver::testAll()
{
	cout << "===== " << __func__ << " =====\n";

	testReadWrite3x3();

	testReadWrite4x4();

	//testDistanceToSolution3x3();
}

void PatternDatabaseDriver::testReadWrite3x3()
{
	cout << "===== " << __func__ << " =====\n";

	PatternDatabase3x3 database;
	PatternDatabase3x3 database2;

	ofstream outFile;
	ifstream inFile;

	for (uint32_t i = 0; i < 1000000; i++) {
		database.insert(pair<Checksum3x3, uint16_t>(Checksum3x3(i), static_cast<uint16_t>(i)));
	}

	outFile.open("test" + database3x3FileName);
	database.writeToFile(outFile);

	inFile.open("test" + database3x3FileName);
	database2.readFromFile(inFile);

	cout << database.size() << " " << database2.size() << '\n';
}

void PatternDatabaseDriver::testReadWrite4x4()
{
	cout << "===== " << __func__ << " =====\n";

	PatternDatabase4x4 database;
	PatternDatabase4x4 database2;

	ofstream outFile;
	ifstream inFile;

	for (uint32_t i = 0; i < 1000; i++) {
		database.insert(pair<Checksum4x4, uint16_t>(Checksum4x4(i), static_cast<uint16_t>(i)));
	}

	outFile.open(database4x4FileName);
	database.writeToFile(outFile);

	inFile.open(database4x4FileName);
	database2.readFromFile(inFile);

	cout << database.size() << " " << database2.size() << '\n';
}

void PatternDatabaseDriver::testDistanceToSolution3x3(const PatternDatabase3x3 & database)
{
	//cout << database.size() << '\n';

	//SliderBoard board(3, 3);
	//board.slideRightSafe();
	//board.slideDownSafe();
	//board.slideDownSafe();

	////Checksum3x3 checksum(board);

	////PatternDatabase3x3::const_iterator it = database.find(checksum);

	//board.print();

	////cout << "Distance from solution = " << it->second << '\n';
}

void PatternDatabaseDriver::generatePatternDatabase3x3()
{
}

void PatternDatabaseDriver::generatePatternDatabase4x4()
{
}
