#include <cstddef>
#include <cmath>
//#include <iterator>
//#include <iostream>

#include "point.hpp"


namespace coordinates
{


 Point::Point()
 : m_x(0)
 , m_y(0)
 , m_distancePointZero(0)
 {
 }

 Point::Point(int a_x, int a_y)
 : m_x(a_x)
 , m_y(a_y)
 {
 	m_distancePointZero = sqrt(m_x * m_x + m_y * m_y);
 }

int Point::get_x() const
{
	return m_x;
}

void Point::set_x(int a_x)
{
	m_x = a_x;
	m_distancePointZero = sqrt(m_x * m_x + m_y * m_y);
}

int Point::get_y() const
{
	return m_y;
}

void Point::set_y(int a_y)
{
	m_y = a_y;
	m_distancePointZero = sqrt(m_x * m_x + m_y * m_y);
}

double Point::distance_from_point_zero() const
{
	return m_distancePointZero;
}


bool Point::operator<(Point const& a_point) const
{
	return m_distancePointZero < a_point.m_distancePointZero;
}

bool Point::operator<=(Point const& a_point) const
{
	return m_distancePointZero <= a_point.m_distancePointZero;
}

bool Point::operator==(Point const& a_point) const
{
	return (m_x == a_point.m_x && m_y == a_point.m_y);
}

std::ostream& Point::operator<<(std::ostream& a_os)
{
	a_os << "x:" << m_x << '\n';
	a_os << "y:" << m_y << '\n';
	a_os << "distance:" << m_distancePointZero << '\n';

	return a_os;
}

void swap_points(Point& a_first, Point& a_second)
{
	Point temp(a_first);
	a_first = a_second;
	a_second = temp;
}

bool operator>(Point const& a_first, Point const& a_second)
{
	return !(a_first <= a_second);
}

bool operator>=(Point const& a_first, Point const& a_second)
{
	return !(a_first < a_second);
}

bool operator!=(Point const& a_first, Point const& a_second)
{
	return !(a_first == a_second);
}


}//namespace coordinates