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

	//uint32_t checksum = board.calc32BitChecksum();
	//cout << "Checksum = " << checksum << '\n';

	//SliderBoard board2(3, 3, checksum);
	//board2.print();

	return 0;
}

int SliderBoardDriver::largeBoard()
{
	SliderBoard board(5,5);
	shuffle(board, 16 * 16);
	board.print();
	
	//uint64_t checksum = board.calc64BitChecksum();
	//cout << "64 bit checksum = " << checksum << '\n'
	//	<< "32 bit checksum = " << board.calc32BitChecksum() << '\n';
	//
	//SliderBoard board2(5,5, checksum);
	//board2.print();

	return 0;
}

int SliderBoardDriver::testShift()
{
	cout << "54321 truncated to 100's place is "
		<< shift<uint32_t>(54321, 10, 2) << '\n';

	return 0;
}
