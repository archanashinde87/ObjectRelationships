#include "Point2D.h"

void Point2D::setPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}
std::ostream& operator<<(std::ostream& out, const Point2D& point)
{
	out << "(" << point.m_x << ", " << point.m_y << ")\n";
	return out;
}
