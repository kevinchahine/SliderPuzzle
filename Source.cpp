#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

#include "SliderUtility.h"
#include "Slide.h"

#include "PatternDatabaseGenerator.h"

// Solvers
#include "SliderSolver.h"
#include "SliderSolver3x3.h"

// Slide Sequences
#include "FastSlideSequence.h"
#include "SafeSlideSequence.h"

// Include Drivers for testing
#include "ChecksumDriver.h"
#include "MatrixDriver.h"
#include "SliderBoardDriver.h"
#include "SliderUtilityDriver.h"
#include "PatternDatabaseDriver.h"
#include "SliderSolverDriver.h"

using namespace std;

default_random_engine generator(static_cast<unsigned int>(time(0)));

string database3x3FileName = "database3x3.dat";
string database4x4FileName = "database4x4.dat";

int main()
{
	//MatrixDriver m;
	//m.test();
	//m.testAssign();

	//SliderBoardDriver s;
	//s.test();
	//s.slide();
	//s.testChecksum();
	//s.largeBoard();
	//s.shift();
	//s.isSolved();
	//s.methodPointers();

	// ===== GENERATES PATTERN DATABASE 3X3 =====
	PatternDatabase3x3 database3x3;
	
	//PatternDatabaseGenerator patternDatabaseGenerator;
	//database3x3(
	//	patternDatabaseGenerator.generate3x3PatternDatabase());
	
	// ===== WRITE PATTERN DATABASE 3X3 TO FILE =====
	//ofstream outFile(database3x3FileName);
	//database3x3.writeToFile(outFile);

	// ===== READ PATTERN DATABASE 3X3 FROM FILE =====
	ifstream inFile(database3x3FileName);
	database3x3.readFromFile(inFile);

	//SliderBoard slider;
	//shuffle(slider, 10);

	//SliderUtilityDriver::testShift64();

	//ChecksumDriver checksumDriver;
	//checksumDriver.test4x4Checksum();
	//checksumDriver.test3x3Checksum();
	
	//PatternDatabaseDriver patternDatabaseDriver;
	//patternDatabaseDriver.testReadWrite3x3();
	//patternDatabaseDriver.testReadWrite4x4();
	//patternDatabaseDriver.testDistanceToSolution3x3(database3x3);

	//PatternDatabaseGenerator patternGenerator;
	//PatternDatabase3x3 database = patternGenerator.generate3x3PatternDatabase();
	//cout << "size = " << database.size() << '\n';

	SliderSolverDriver solverDriver;
	//solverDriver.solve3x3(database3x3);
	solverDriver.manualHillClimb3x3(database3x3);

	return 0;
}