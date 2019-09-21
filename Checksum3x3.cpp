#include "Checksum3x3.h"

#include <iostream>

using namespace std;

Checksum3x3::Checksum3x3(const SliderBoard & board)
{
	setChecksum(board);
}

void Checksum3x3::setChecksum(const SliderBoard & board)
{
#if _DEBUG
	if (board.getNRows() != 3 || board.getNCols() != 3) {
		cerr << __FILE__ << " line " << __LINE__ << '\n'
			<< "exception: SliderBoard has a size other than 3x3\n";
		return;
	}
#endif

	register uint32_t tempChecksum = 0;

	const size_t N_ELEMENTS = board.getNElements();

	for (size_t i = 0; i < N_ELEMENTS; i++) {
		tempChecksum += board.at(i) * static_cast<uint32_t>(pow(N_ELEMENTS, i));
	}

	this->checksum = tempChecksum;
}

void Checksum3x3::calcSliderBoard(SliderBoard & board) const
{
#if _DEBUG
	if (board.getNRows() != 3 || board.getNCols() != 3) {
		cerr << __FILE__ << " line " << __LINE__ << '\n'
			<< "exception: SliderBoard has a size other than 3x3\n";
		return;
	}
#endif
	uint32_t checksum3x3 = 0;
	const int N_ELEMENTS = board.getNElements();

	register uint32_t tempA;
	register uint32_t tempB;

	for (int i = 0; i < N_ELEMENTS; i++)
	{
		tempA =
			static_cast<uint32_t>(shift(checksum3x3, N_ELEMENTS, -i));
		tempB =
			static_cast<uint32_t>(shift(checksum3x3, N_ELEMENTS, -(i + 1))) * N_ELEMENTS;

		board.at(i) = static_cast<uint8_t>(tempA - tempB);
	}
}
