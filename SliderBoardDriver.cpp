#include "SliderBoardDriver.h"

using namespace std;

int SliderBoardDriver::test()
{
	SliderBoard board(4, 6);
	SliderBoard copy(board);
	SliderBoard move(SliderBoard(7, 8));

	board.print();

	copy.print();

	move.print();

	return 0;
}

int SliderBoardDriver::slide()
{
	SliderBoard board(4, 5);

	board.slideUpSafe();
	board.print();
	board.slideRightSafe();
	board.print();
	board.slideDownSafe();
	board.print();
	board.slideDownSafe();
	board.print();
	board.slideLeftSafe();
	board.print();
	board.slideLeftSafe();
	board.print();
	board.slideDownSafe();
	board.print();
	board.slideRightSafe();
	board.print();
	board.slideRightSafe();
	board.print();
	board.slideDownSafe();
	board.print();
	board.slideRightSafe();
	board.print();
	board.slideRightSafe();
	board.print();
	board.slideRightSafe();
	board.print();

	return 0;
}

int SliderBoardDriver::testChecksum()
{
	SliderBoard board(3, 3);
	board.slideUpSafe();
	board.slideLeftSafe();
	board.slideLeftSafe();
	board.slideRightSafe();

	board.print();

	uint32_t checksum = board.calcChecksum();
	cout << "Checksum = " << checksum << '\n';

	SliderBoard board2(3, 3, checksum);
	board2.print();

	return 0;
}
