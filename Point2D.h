// This Point2d class is a composition of its parts: location values x and y are part-of Point2D, and their lifespan is tied to that of a given Point2D instance.

#pragma once

#include<iostream>

class Point2D
{
	int m_x{};
	int m_y{};

public:
	// Default Constructor
	Point2D()
		:m_x{ 0 }
		,m_y{ 0 }
	{}
	// Parameterized Constructor
	Point2D(int x, int y)
		:m_x{ x }
		,m_y{ y }
	{}
	void setPoint(int x, int y);
	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
};

