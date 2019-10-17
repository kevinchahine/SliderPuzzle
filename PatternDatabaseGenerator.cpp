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

PatternDatabase4x4 PatternDatabaseGenerator::generate4x4PatternDatabase(int distToSolLimit) const
{
	PatternDatabase4x4 database;

	// Start with a solved board
	SliderBoard currentState(4, 4);

	uint16_t distanceToSolution = 0;

	// first is the SliderBoard state
	// second is the distance to the solution
	queue<pair<SliderBoard, uint16_t>> frontier;
	frontier.push(pair<SliderBoard, uint16_t>(currentState, 0));

	// TODO: REOVE           vvvvvvvvvvvvvvvvvvvvvvvvvvv
	while (!frontier.empty() /*&& database.size() < 100000*/) {
		// TODO: REMOVE
		if (database.size() % 100000 == 0) {
			cout << database.size() << '\n';
		}

		// 0.) Pop next state from the frontier 
		//		to evaluate it.
		currentState = frontier.front().first;
		uint16_t distToSol = frontier.front().second;
		frontier.pop();

		// 0-1.) Is this state within the distance to solution limit?
		//		Only add states to the database iff they are less than a defined limit
		//		from the solution. This is to prevent the database from getting to huge
		//		and cause errors.
		if (distToSol > distToSolLimit)
			continue;	// State is to far from solution, we don't want our database to be
						// gibabytes large.

		// 1.) Add the checksum of the state to database along with its distance 
		//		to the solution, but only if the state has not been added yet.
		bool stateIsNew = database.insert(
			pair<Checksum4x4, uint16_t>(
				Checksum4x4(currentState), distToSol)).second;

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

	cout << "database size = " << database.size() << "press any key";
	cin.get();

	return database;
}
