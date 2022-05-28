#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>

#include "car.hpp"

namespace game
{


Car::Car(char a_name, size_t a_length, bool a_orientation, struct Coordinates a_loctaion)
: m_name(a_name)
, m_length(a_length)
, m_orientation(a_orientation)
, m_location(a_loctaion)
{
	assert((m_orientation == 1 || m_orientation == 0) && ("orientation is invalid"));
}

char Car::length()
{
	return m_length;
}

bool Car::orientation()
{
	return m_orientation;
}





}//namespace game