#pragma once

#include <iostream>
#include <fstream>
#include <map>

template <typename T>
class PatternDatabase : public std::map<T, uint16_t>
{
public:
	PatternDatabase();
	PatternDatabase(const PatternDatabase & database);
	PatternDatabase(PatternDatabase && database);
	~PatternDatabase();

	PatternDatabase & operator=(const PatternDatabase & database);
	PatternDatabase & operator=(PatternDatabase && database);

	//uint16_t getDistanceToSolution(const Checksum & checksum) const;

	virtual void writeToFile(std::ofstream & outFile) const = 0;
	
	virtual void readFromFile(std::ifstream & inFile) = 0;
};

template<typename T>
inline PatternDatabase<T>::PatternDatabase() {}

template<typename T>
inline PatternDatabase<T>::PatternDatabase(const PatternDatabase & database) :
	std::map<T, uint16_t>(database)
{
}

template<typename T>
inline PatternDatabase<T>::PatternDatabase(PatternDatabase && database) :
	std::map<T, uint16_t>(std::move(database))
{
}

template<typename T>
inline PatternDatabase<T>::~PatternDatabase() {}

template<typename T>
inline PatternDatabase<T> & PatternDatabase<T>::operator=(const PatternDatabase<T> & database)
{
	this->std::map<T, uint16_t>::operator=(database);

	return *this;
}

template<typename T>
inline PatternDatabase<T> & PatternDatabase<T>::operator=(PatternDatabase<T> && database)
{
	this->std::map<T, uint16_t>::operator=(std::move(database));

	return *this;
}

