#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

#include "SliderUtility.h"
#include "Slide.h"

// Include Drivers for testing
#include "ChecksumDriver.h"
#include "MatrixDriver.h"
#include "SliderBoardDriver.h"
#include "SliderUtilityDriver.h"

using namespace std;

default_random_engine generator(static_cast<unsigned int>(time(0)));

int main()
{
	//MatrixDriver m;
	//m.test();

	//SliderBoardDriver s;
	//s.test();
	//s.slide();
	//s.testChecksum();
	//s.largeBoard();
	//s.shift();

	//SliderBoard slider;
	//shuffle(slider, 10);

	//bool (SliderBoard::*slidePtr)() = &SliderBoard::slideDownSafe;
	//SafeSlide_T slide = SliderBoard::slideDownSafe;
	//(slider.*slidePtr)();

	//slider.print();
	
	//SliderUtilityDriver::testShift64();

	ChecksumDriver checksumDriver;
	checksumDriver.test4x4Checksum();

	return 0;
}