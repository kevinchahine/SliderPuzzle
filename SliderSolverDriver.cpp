#include "SliderSolverDriver.h"

using namespace std;

int SliderSolverDriver::solve3x3(const PatternDatabase3x3 & database)
{
	SliderBoard board;
	board.shuffle();
	board.print();

	SliderSolver3x3 solver(board);
	solver.setDatabasePtr(&database);

	FastSlideSequence solutionSequence = solver.solve();
	   
	return 0;
}

int SliderSolverDriver::manualHillClimb3x3(const PatternDatabase3x3 & database)
{
	SliderBoard board(3, 3);

	PatternDatabase3x3::const_iterator it;

	while (true)
	{
		board.shuffle();
		board.shuffle();
		board.shuffle();
		board.shuffle();
		
		while (!board.isSolved())
		{
			// ======== Show analytics ==============

			board.print();
			cout << "\tDistance to solution: ";

			cout << database.find(Checksum3x3(board))->second << '\n';

			// -------- Analyze future moves --------

			uint16_t minDist = UINT16_MAX;
			Slide_T minMove = Slide_T::NONE;

			// --- UP
			cout << setw(7) << "UP: ";
			if (board.isSlideUpValid() == true)
			{
				board.slideUpFast();
				uint16_t temp = database.find(Checksum3x3(board))->second;
				cout << temp << '\n';

				if (temp < minDist) {
					minDist = temp;
					minMove = Slide_T::UP;
				}

				board.slideDownFast();
			}
			else cout << "not valid\n";

			// --- DOWN
			cout << setw(7) << "DOWN: ";
			if (board.isSlideDownValid() == true)
			{
				board.slideDownFast();
				uint16_t temp = database.find(Checksum3x3(board))->second;
				cout << temp << '\n';

				if (temp < minDist) {
					minDist = temp;
					minMove = Slide_T::DOWN;
				}

				board.slideUpFast();
			}
			else cout << "not valid\n";

			// --- LEFT
			cout << setw(7) << "LEFT: ";
			if (board.isSlideLeftValid() == true)
			{
				board.slideLeftFast();
				uint16_t temp = database.find(Checksum3x3(board))->second;
				cout << temp << '\n';
				
				if (temp < minDist) {
					minDist = temp;
					minMove = Slide_T::LEFT;
				}

				board.slideRightFast();
			}
			else cout << "not valid\n";

			// --- RIGHT
			cout << setw(7) << "RIGHT: ";
			if (board.isSlideRightValid() == true)
			{
				board.slideRightFast();
				uint16_t temp = database.find(Checksum3x3(board))->second;
				cout << temp << '\n';

				if (temp < minDist) {
					minDist = temp;
					minMove = Slide_T::RIGHT;
				}

				board.slideLeftFast();
			}
			else cout << "not valid\n";

			// ======== Prompt user for input =======

			/*char input;
			cout << "Enter input (a s d w):";
			cin >> input;

			input = tolower(input);

			Slide_T slide;

			switch (input)
			{
			case 'w':	slide = Slide_T::UP;	break;
			case 's':	slide = Slide_T::DOWN;	break;
			case 'a':	slide = Slide_T::LEFT;	break;
			case 'd':	slide = Slide_T::RIGHT;	break;
			}
			*/

			board.slideSafe(minMove);
		}

		board.print();

		cin.get();
		cout << "\n====== Board is solved ==========\n\n\n";
	}

	return 0;
}
