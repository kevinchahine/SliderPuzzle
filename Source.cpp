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

	// ===== GENERATES PATTERN DATABASE 3X3 =====
	PatternDatabase3x3 database3x3;
	
	if (true) {
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

	//PatternDatabaseGenerator patternGenerator;
	//PatternDatabase3x3 database = patternGenerator.generate3x3PatternDatabase();
	//cout << "size = " << database.size() << '\n';

	//SliderSolverDriver solverDriver;
	//solverDriver.solve3x3(database3x3);
	//solverDriver.manualHillClimb3x3(database3x3);
	
	cout << "Press any key...";
	cin.get();
	return 0;
}