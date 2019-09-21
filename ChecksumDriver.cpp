#include "ChecksumDriver.h"

using namespace std;

void ChecksumDriver::test3x3Checksum()
{
	SliderBoard board(3, 3);
	board.shuffle();
	board.print();

	Checksum3x3 check(board);

	cout << check << '\n';

	SliderBoard b(3, 3);
	check.calcSliderBoard(b);

	board.print();
}

void ChecksumDriver::test4x4Checksum()
{
	SliderBoard board(4, 4);
	board.shuffle();
	board.print();

	Checksum4x4 check(board);

	cout << check << '\n';

	SliderBoard b(4, 4);

	check.calcSliderBoard(b);

	board.print();
}
