#include "Checksum4x4.h"

#include <iostream>

using namespace std;

void Checksum4x4::calcChecksum(const SliderBoard & board)
{
	#if _DEBUG
	if (board.getNRows() != 4 || board.getNCols() != 4) {
		cerr << __FILE__ << " line " << __LINE__ << '\n'
			<< "exception: SliderBoard has a size other than 4x4\n";
		return;
	}
	#endif

	register uint64_t tempChecksum = 0;

	for (size_t cellIndex = board.size() - 1; cellIndex != 0; cellIndex--) {
		#if _DEBUG 
		if (board.at(cellIndex) > 15)
		{
			cerr << __FILE__ << " line " << __LINE__ << '\n'
				<< "exception: cell value = " 
				<< static_cast<int>(board.at(cellIndex))
				<< " is greater than 15\n";
			return;
		}
		#endif

		tempChecksum |= board.at(cellIndex);
		tempChecksum <<= 4;
	}

	tempChecksum = tempChecksum | board.at(0);
	
	this->checksumVal = tempChecksum;
}

SliderBoard Checksum4x4::toSliderBoard() const
{
	SliderBoard board;

	register uint64_t tempChecksum = this->checksumVal;

	for (size_t cellIndex = 0; cellIndex < board.size(); cellIndex++)
	{
		uint8_t cellVal = tempChecksum & 0b1111;

		board.at(cellIndex) = cellVal;

		tempChecksum >>= 4;
	}

	board.alignPositionOfEmptySlot();

	return board;
}
