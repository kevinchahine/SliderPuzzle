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

	// Start with a solved board
	SliderBoard currentState(3, 3);

	uint16_t distanceToSolution = 0;

	// first is the SliderBoard state
	// second is the distance to the solution
	queue<pair<SliderBoard, uint16_t>> frontier;
	frontier.push(pair<SliderBoard, uint16_t>(currentState, 0));

	while (!frontier.empty()) {

		// 0.) Pop next state from the frontier 
		//		to evaluate it.
		currentState = frontier.front().first;
		uint16_t distToSol = frontier.front().second;
		frontier.pop();
		
		// 1.) Add the checksum of the state to database along with its distance 
		//		to the solution, but only if the state has not been added yet.
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
			currentState.slideUpSafe();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideDownSafe();
		}
		
		// 3-2.) Slide Down
		if (currentState.isSlideDownValid()) {
			currentState.slideDownSafe();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideUpSafe();
		}
		
		// 3-3.) Slide Left
		if (currentState.isSlideLeftValid()) {
			currentState.slideLeftSafe();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideRightSafe();
		}
		
		// 3-4.) Slide Right
		if (currentState.isSlideRightValid()) {
			currentState.slideRightSafe();
			frontier.push(pair<SliderBoard, uint16_t>(currentState, distToSol + 1));
			currentState.slideLeftSafe();
		}

	} // end while(frontier.empty() == true)
	
	return database;
}
