#include "ChecksumDriver.h"

using namespace std;

void ChecksumDriver::testAll()
{
	testAccessors();

	testChecksumConstructors();

	testCalcChecksum();

	testChecksums();

	test3x3Checksum();

	test4x4Checksum();
}

void ChecksumDriver::testAccessors()
{
	Checksum3x3 three(333);
	Checksum4x4 four(444);

	Checksum & ref3 = three;
	Checksum & ref4 = four;

	cout << "three = " << ref3 << '\t' << ref3.getChecksumValue() << '\n';
	cout << "four = " << ref4 << '\t' << ref4.getChecksumValue() << '\n';

	ref3.setChecksumValue(3330);
	ref4.setChecksumValue(4440);

	cout << ref3 << '\n'
		<< ref4 << '\n';
}

void ChecksumDriver::testCalcChecksum()
{
	SliderBoard board3x3(3, 3);
	SliderBoard board4x4(4, 4);

	board3x3.shuffle();
	board4x4.shuffle();

	board3x3.print();
	board4x4.print();

	Checksum & ref3 = *(new Checksum3x3(board3x3));
	Checksum & ref4 = *(new Checksum4x4(board4x4));

	board3x3.print();
	board4x4.print();

	delete &ref3;
	delete &ref4;
}

void ChecksumDriver::testChecksumConstructors()
{
	cout << "===== ChecksumDriver testConstructors() =====\n";

	//ChecksumTemplate<uint32_t> ctDef;
	//ChecksumTemplate<uint32_t> ctFull(4);
	//ChecksumTemplate<uint32_t> ctCopy(ctFull);
	//ChecksumTemplate<uint32_t> ctMove(ChecksumTemplate<uint32_t>(5));

	Checksum3x3 cFull(4);
	Checksum3x3 cCopy(cFull);
	Checksum3x3 cMove(Checksum3x3(5));

	cout 
		 << "\nChecksum3x3"
		 << "\n\tFull "  << cFull
		 << "\n\tCopy "  << cCopy
		 << "\n\tMove "  << cMove
		 << "\n";

	Checksum4x4 c4Full(4);
	Checksum4x4 c4Copy(c4Full);
	Checksum4x4 c4Move(Checksum4x4(5));

	cout
		<< "\nChecksum4x4"
		<< "\n\tFull " << c4Full
		<< "\n\tCopy " << c4Copy
		<< "\n\tMove " << c4Move
		<< "\n";
}

void ChecksumDriver::testChecksums()
{
	Checksum3x3 three(3);
	Checksum4x4 four(4);

	Checksum & check3 = three;
	Checksum & check4 = four;

	check3.setChecksumValue(33);
	check4.setChecksumValue(44);

	cout << check3 << '\t' << check3.getChecksumValue() << '\n'
		<< check4 << '\t' << check4.getChecksumValue() << '\n';

	Checksum3x3 check3copy = three;
	Checksum4x4 check4copy = four;
	
	cout << check3 << '\t' << check3.getChecksumValue() << '\n'
		<< check4 << '\t' << check4.getChecksumValue() << '\n';
	
	check3 = Checksum3x3(33);
	check4 = Checksum4x4(44);

	cout << check3copy << '\t' << check3copy.getChecksumValue() << '\n'
		<< check4copy << '\t' << check4copy.getChecksumValue() << '\n';

	Checksum * check3a = new Checksum3x3(33);
	Checksum * check4a = new Checksum4x4(44);

	cout 
		<< (check3 < *check3a) << '\n'
		<< (check3 == *check3a) << '\n'
		<< (check4 < *check4a) << '\n'
		<< (check4 == *check4a) << '\n';
}

void ChecksumDriver::test3x3Checksum()
{
	/*SliderBoard board(3, 3);
	board.shuffle();
	board.print();*/

	//Checksum3x3 check(board);

	// TODO: UNCOMMENT cout << check << '\n';

	// TODO: UNCOMMENT SliderBoard b = check.toSliderBoard();

	//board.print();
}

void ChecksumDriver::test4x4Checksum()
{
	/*SliderBoard board(4, 4);
	board.shuffle();
	board.print();*/

	// TODO: UNCOMMENT Checksum4x4 check(board);

	// TODO: UNCOMMENT cout << check << '\n';

	// TODO: UNCOMMENT SliderBoard b = check.toSliderBoard();

	//board.print();
}
