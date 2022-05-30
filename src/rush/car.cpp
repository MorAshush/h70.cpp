#include <cstddef>
#include <cassert>
//#include <cstring>
//#include <iostream>

#include "car.hpp"

namespace game
{


Car::Car(std::string  a_name, size_t a_length, bool a_orientation, struct Coordinates a_loctaion)
: m_name(a_name)
, m_length(a_length)
, m_orientation(a_orientation)
, m_location(a_loctaion)
{
	assert((m_orientation == 1 || m_orientation == 0) && ("orientation is invalid"));
}

size_t Car::length() const
{
	return m_length;
}

bool Car::orientation() const
{
	return m_orientation;
}

Coordinates Car::location() const
{
	return m_location;
}



}//namespace game