#include "SliderUtility.h"

using namespace std;

void shuffle(SliderBoard & board, size_t count)
{
	uniform_int_distribution<int> dist(0, 3);

	for (size_t i = 0; i < count; i++) {
		int move = dist(generator);

		switch (move)
		{
		case 0:	// UP
			board.slideUpSafe();
			break;
		case 1: // DOWN
			board.slideDownSafe();
			break;
		case 2: // LEFT
			board.slideLeftSafe();
			break;
		case 3:	// RIGHT
			board.slideRightSafe();
			break;
		}
	}
}

