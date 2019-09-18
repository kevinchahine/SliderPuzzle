#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

#include "MatrixDriver.h"
#include "SliderBoardDriver.h"
#include "SliderUtility.h"

using namespace std;

default_random_engine generator(static_cast<unsigned int>(time(0)));

int main()
{
	MatrixDriver m;
	//m.test();

	SliderBoardDriver s;
	//s.test();
	//s.slide();

	SliderBoard slider;
	shuffle(slider, 10);

	slider.print();

	return 0;
}