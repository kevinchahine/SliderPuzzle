#pragma once

#include <iostream>

class Slide_T {
public:
	enum SlideValue : char
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE,
	};

	Slide_T() = default;
	Slide_T(const Slide_T & slideT) = default;
	Slide_T(Slide_T && slideT) = default;
	constexpr Slide_T(SlideValue slide) : slide(slide) {}
	~Slide_T() = default;

	Slide_T & operator=(const Slide_T & slide);
	Slide_T & operator=(Slide_T && slide) noexcept;

	operator SlideValue() const { return slide; }
	explicit operator bool() = delete;

	//constexpr bool operator==(Slide_T a) const { return slide == a.slide; }
	//constexpr bool operator!=(Slide_T a) const { return slide == a.slide; }

	friend std::ostream & operator<<(std::ostream & os, const Slide_T & slideObj);
	friend std::ostream & operator<<(std::ostream & os, Slide_T && slideObj);

protected:
	SlideValue slide;
};
