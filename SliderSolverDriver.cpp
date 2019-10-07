#include "SliderSolverDriver.h"

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
