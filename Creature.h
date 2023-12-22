//This Creature is also a composition of its parts. The creature’s name and location have one parent, and their lifetime is tied to that of the Creature they are part of.

#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include "Point2D.h"

class Creature
{
	std::string m_name{};
	Point2D m_location{};

public:
	Creature(std::string_view name, const Point2D& location)
		: m_name{ name }
		, m_location{ location }
	{}

	void moveTo(int x, int y);
	friend std::ostream& operator<<(std::ostream& out, const Creature& creature);

};

