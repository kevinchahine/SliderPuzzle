#include "ChecksumDriver.h"

using namespace std;

void ChecksumDriver::test3x3Checksum()
{
	SliderBoard board(3, 3);
	board.shuffle();
	board.print();

	Checksum3x3 check(board);

	// TODO: UNCOMMENT cout << check << '\n';

	// TODO: UNCOMMENT SliderBoard b = check.toSliderBoard();

	board.print();
}

void ChecksumDriver::test4x4Checksum()
{
	SliderBoard board(4, 4);
	board.shuffle();
	board.print();

	// TODO: UNCOMMENT Checksum4x4 check(board);

	// TODO: UNCOMMENT cout << check << '\n';

	// TODO: UNCOMMENT SliderBoard b = check.toSliderBoard();

	board.print();
}
