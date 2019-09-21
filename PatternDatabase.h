#pragma once

#include <map>

template <typename T>
class PatternDatabase : public std::map<T, uint16_t>
{
public:
	PatternDatabase();
	~PatternDatabase();
};

template<typename T>
inline PatternDatabase<T>::PatternDatabase() {}

template<typename T>
inline PatternDatabase<T>::~PatternDatabase() {}
