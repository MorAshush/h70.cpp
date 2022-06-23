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

std::string Car::name() const
{
	return m_name;
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

bool Car::is_valid_direction(char a_direction)
{
	if(m_orientation && (a_direction == 'l' || a_direction == 'r'))
	{
		return true;
	}
	else if(!m_orientation && (a_direction == 'd' || a_direction == 'u'))
	{
		return true;
	}

	return false;
}
/*
Coordinates Car::get_new_location(char a_direction)
{
	Coordinates newLocation = m_location;
	if(a_direction == 'd')
	{
		++newLocation.m_row;
	}
	if(a_direction == 'u')
	{
		--newLocation.m_row;
	}
	if(a_direction == 'l')
	{
		--newLocation.m_column;
	}
	if(a_direction == 'r')
	{
		++newLocation.m_column;
	}

	return newLocation;
}
*/
void Car::move(char a_direction)
{
	if(a_direction == 'd')
	{
		++m_location.m_row;
	}
	if(a_direction == 'u')
	{
		--m_location.m_row;
	}
	if(a_direction == 'l')
	{
		--m_location.m_column;
	}
	if(a_direction == 'r')
	{
		++m_location.m_column;
	}
}
/*
void Car::set_location(struct Coordinates a_location)
{
	m_location.m_row = a_location.m_row;
	m_location.m_column = a_location.m_column;
}
*/
}//namespace game