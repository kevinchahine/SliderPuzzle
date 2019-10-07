#pragma once

#include <iostream>

enum class Slide_T : char
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE,
};

//void print(const Slide_T & slide, std::ostream & os = std::cout)
//{
//	switch (slide)
//	{
//	case Slide_T::UP:		os << "UP";		break;
//	case Slide_T::DOWN:		os << "DOWN";	break;
//	case Slide_T::LEFT:		os << "LEFT";	break;
//	case Slide_T::RIGHT:	os << "RIGHT";	break;
//	case Slide_T::NONE:		os << "NONE";	break;
//	default:
//		std::cerr << "default case triggered "
//			<< __FILE__ << " line " << __LINE__
//			<< " slide = " << static_cast<char>(slide);
//	}
//}

std::ostream & operator<<(std::ostream & os, const Slide_T & slide);
//std::ostream & operator<<(std::ostream & os, const Slide_T & slide)
//{
//	switch (slide)
//	{
//	case Slide_T::UP:		os << "UP";		break;
//	case Slide_T::DOWN:		os << "DOWN";	break;
//	case Slide_T::LEFT:		os << "LEFT";	break;
//	case Slide_T::RIGHT:	os << "RIGHT";	break;
//	case Slide_T::NONE:		os << "NONE";	break;
//	default:
//		std::cerr << "default case triggered "
//			<< __FILE__ << " line " << __LINE__
//			<< " slide = " << static_cast<char>(slide);
//	}
//
//	return os;
//}
