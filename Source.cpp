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

using namespace std;

default_random_engine generator(static_cast<unsigned int>(time(0)));

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

	//SliderBoard slider;
	//shuffle(slider, 10);

	//bool (SliderBoard::*slidePtr)() = &SliderBoard::slideDownSafe;
	//SafeSlide_T slide = SliderBoard::slideDownSafe;
	//(slider.*slidePtr)();

	//slider.print();
	
	//SliderUtilityDriver::testShift64();

	//ChecksumDriver checksumDriver;
	//checksumDriver.test4x4Checksum();
	//checksumDriver.test3x3Checksum();
	
	//PatternDatabaseDriver patternDatabaseDriver;
	//patternDatabaseDriver.testReadWrite3x3();
	//patternDatabaseDriver.testReadWrite4x4();

	//PatternDatabaseGenerator patternGenerator;
	//PatternDatabase3x3 database = patternGenerator.generate3x3PatternDatabase();
	//cout << "size = " << database.size() << '\n';

	SliderBoard board(3, 3);
	board.shuffle();

	SliderSolver3x3 solver3x3;
	FastSlideSequence solution = solver3x3.solve(board);

	return 0;
}