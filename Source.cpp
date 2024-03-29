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
#include "CoordinateDriver.h"
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
	Coordinate c(3, 4);
	c = Coordinate(2, 34);
	clock_t startTime, endTime;

	//CoordinateDriver coordDriver;
	//coordDriver.testAssignmentOperator();
	
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

	// ===== GENERATES PATTERN DATABASE 3x3 =====
	PatternDatabase3x3 database3x3;
	
	if (false) {
		cout << "=== Generating pattern database 3x3 ===\n";
		cout << "...";

		startTime = clock();

		PatternDatabaseGenerator patternDatabaseGenerator;
		database3x3 =
			patternDatabaseGenerator.generate3x3PatternDatabase();

		endTime = clock();

		cout << "done\tgenerated " << database3x3.size()
			<< " in " << (endTime - startTime) / 1000.0
			<< " sec\n";

		// ===== WRITE PATTERN DATABASE 3X3 TO FILE =====
		cout << "=== Writting database to file ===\n";

		ofstream outFile(database3x3FileName);
		database3x3.writeToFile(outFile);
	}
	if (false) {
		// ===== READ PATTERN DATABASE 3X3 FROM FILE =====
		cout << "=== Reading database from file ===\n";

		ifstream inFile(database3x3FileName);
		database3x3.readFromFile(inFile);
	}
	
	// ===== GENERATES PATTERN DATABASE 4x4 =====
	PatternDatabase4x4 database4x4;
	if (true) {
		cout << "=== Generating pattern database 4x4 ===\n";
		
		startTime = clock();

		PatternDatabaseGenerator patternDatabaseGenerator;
		database4x4 =
			patternDatabaseGenerator.generate4x4PatternDatabase(20);

		endTime = clock();

		cout << "done\tgenerated " << database4x4.size()
			<< " in " << (endTime - startTime) / 1000.0
			<< " sec\n";

		// ===== WRITE PATTERN DATABASE 4x4 TO FILE =====
		cout << "=== Writting database to file ===\n";

		ofstream outFile(database4x4FileName);
		cout << "\tWritting to " << database4x4FileName;
		database4x4.writeToFile(outFile);
		cout << "done\n";
	}
	if (false) {
		// ===== READ PATTERN DATABASE 4X4 FROM FILE =====
		cout << "=== Reading database from file ===\n";

		ifstream inFile(database4x4FileName);
		database4x4.readFromFile(inFile);
	}

	//SliderBoard slider;
	//shuffle(slider, 10);

	//SliderUtilityDriver::testShift64();

	// ====================== CHECKSUM DRIVER =================================
	//ChecksumDriver checksumDriver;
	//checksumDriver.testAll();
	
	// ====================== PATTERN DATABASE DRIVER =========================
	//PatternDatabaseDriver patternDatabaseDriver;
	//patternDatabaseDriver.testReadWrite3x3();
	//patternDatabaseDriver.testReadWrite4x4();
	//patternDatabaseDriver.testDistanceToSolution3x3(database3x3);

	//SliderSolverDriver solverDriver;
	//solverDriver.solve3x3(database3x3);
	//solverDriver.manualHillClimb3x3(database3x3);
	
	cin.get();
	return 0;
}