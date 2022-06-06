#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

namespace coordinates
{


class Point
{

public:
	Point();
	Point(int a_x, int a_y);

//	Point(Point const& a_point); compiler will do
//	Point& operator=(Point const& a_point); compiler will do

	int get_x() const;
	void set_x(int a_x);

	int get_y() const;
	void set_y(int a_y);

	double distance_from_point_zero() const;

	bool operator<(Point const& a_point) const;
	bool operator<=(Point const& a_point) const;
	bool operator==(Point const& a_point) const;

	std::ostream& operator<<(std::ostream& a_os);

private:
	int m_x;
	int m_y;
	double m_distancePointZero;
};



void swap_points(Point& a_first, Point& a_second);

bool operator>(Point const& a_first, Point const& a_second);

bool operator>=(Point const& a_first, Point const& a_second);

bool operator!=(Point const& a_first, Point const& a_second);


}//namespace coordinates

#endif // POINT_HPP