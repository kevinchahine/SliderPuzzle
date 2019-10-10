#pragma once

#include <iostream>
#include <fstream>
#include <map>

template <typename T>
class PatternDatabase : public std::map<T, uint16_t>
{
public:
	PatternDatabase();
	~PatternDatabase();

	//uint16_t getDistanceToSolution(const Checksum & checksum) const;

	virtual void writeToFile(std::ofstream & outFile) const = 0;
	
	virtual void readFromFile(std::ifstream & inFile) = 0;
};

template<typename T>
inline PatternDatabase<T>::PatternDatabase() {}

template<typename T>
inline PatternDatabase<T>::~PatternDatabase() {}

