#include "ChecksumDriver.h"

using namespace std;

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
