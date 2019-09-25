#include "PatternDatabaseGenerator.h"

#include <queue>

using namespace std;

PatternDatabaseGenerator::PatternDatabaseGenerator()
{
}

PatternDatabaseGenerator::~PatternDatabaseGenerator()
{
}

PatternDatabase3x3 PatternDatabaseGenerator::generate3x3PatternDatabase() const
{
	PatternDatabase3x3 database;

	SliderBoard currentState(3, 3);

	uint16_t distanceToSolution = 0;

	// first is the SliderBoard state
	// second is the distance to the solution
	queue<pair<SliderBoard, uint16_t>> frontier;
	frontier.push(pair<SliderBoard, uint16_t>(currentState, 0));

	while (!frontier.empty()) {
		// 0.) Pop next state from the frontier
		currentState = frontier.front().first;
		uint16_t distToSol = frontier.front().second;
		frontier.pop();

		// 1.) Add the checksum of the state to database along with its distance 
		//		to the solution, but only if the state has not been reached yet.
		bool stateIsNew = database.insert(
			pair<Checksum3x3, uint16_t>(
				Checksum3x3(currentState), distToSol)).second;

		// 2.) If the state has been reached, then we don't want
		//		to add any movements from that state.
		if (!stateIsNew)
			continue;	// This state has already been analysed, skip to the next one

		// 3.) Determine valid moves and push their resulting states to the queue

		// 3-1.) Slide Up
		if (currentState.isSlideUpValid()) {
			currentState.slideUpFast();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideDownFast();
		}
		
		// 3-2.) Slide Down
		if (currentState.isSlideDownValid()) {
			currentState.slideDownFast();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideUpFast();
		}
		
		// 3-3.) Slide Left
		if (currentState.isSlideLeftValid()) {
			currentState.slideLeftFast();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideRightFast();
		}
		
		// 3-4.) Slide Right
		if (currentState.isSlideRightValid()) {
			currentState.slideRightFast();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideLeftFast();
		}
	} // end while(frontier.empty() == true)
	
	return database;
}
