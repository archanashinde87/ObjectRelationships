// Dependencies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Point
{
    double m_x{};
    double m_y{};
    double m_z{};

public:

    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        :m_x{ x }, m_y{ y }, m_z{ z }
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& point); // Point has a dependency on std::ostream here
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

int main()
{
    Point point{ 2.0,3.0,4.0 };

    std::cout << point << '\n'; // the program has a dependency on std::cout here

    return 0;
}

