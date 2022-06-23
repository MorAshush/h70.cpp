#include <vector>
#include <iterator>
#include <map>
#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>


#include "board.hpp"
#include "car.hpp"

namespace game
{


Board::Board()
: m_width(7)
, m_height(7)
, m_board(std::vector<char>(m_width * m_height, 32))
{

}

Board::Board(size_t a_width, size_t a_height)
: m_width(a_width)
, m_height(a_height)
, m_board(std::vector<char>(a_width * a_height, 32))
{
	
}

bool Board::place_car(std::string a_name, size_t a_length, bool a_orientation, struct Coordinates a_location)
{
	if(a_orientation) 
	{
		if(check_horizontal_vailidity(a_length, a_location))
		{
			size_t row = a_location.m_row;
			size_t column = a_location.m_column;

			for(size_t i = 0; i < a_length; ++i)
			{
				m_board[row * m_width + column + i] = a_name;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(check_vertical_vailidity(a_length, a_location))
		{
			size_t row = a_location.m_row;
			size_t column = a_location.m_column;

			for(size_t i = 0; i < a_length; ++i)
			{
				m_board[(row + i) * m_width + column] = a_name;
			}
		}
		else
		{
			return 0;
		}
	}
	
	Car newCar(a_name, a_length, a_orientation, a_location);
	m_cars.insert(std::pair<char, Car>(a_name, newCar));

	return 1;
}

bool Board::move_car(std::string a_name, char a_direction)
{
	bool result = check_direction_vailidity(a_name, a_direction);
	if(result)
	{
		Coordinates newLocation = get_new_location(a_name, a_direction);
		if(newLocation.m_row <= m_height && newLocation.m_column <= m_width)
		{
			change_location_on_board(a_name, a_direction);
			set_car_location(a_name, newLocation);

			return 1;
		}
	}
	
	return 0;
}

bool Board::is_victory()
{
	char carsNames[] = {'Y', 'R', 'G', 'O', 'B', 'W'};

	for(size_t i = 0; i < std::strlen(carsNames); ++i)
	{
		if(m_cars.at(carsNames[i]).m_orientation)
		{
			bool result = check_victory(m_cars.at(carsNames[i]).m_length, m_cars.at(carsNames[i]).m_location);
			if(result)
			{
				return true;
			}
		}
	}

	return false;
}

size_t Board::width()
{
	return m_width;
}

size_t Board::height()
{
	return m_height;
}

void Board::print()
{
	for(size_t i = 0; i < width(); ++i)
	{
		std::cout << "---";
	}
	std::cout << "--\n";
	for(size_t i = 0; i < height(); ++i)
	{
		std::cout << '|';

		for(size_t j = 0; j < width(); ++j)
		{
			std::cout << ' ' << m_board[i * width() + j] << ' ';
		}

		if(i != height()/2)
		{
			std::cout << '|';
		}

		std::cout << '\n';
	}

	for(size_t i = 0; i < width(); ++i)
	{
		std::cout << "---";
	}

	std::cout << "--\n";
}

bool Board::check_horizontal_vailidity(size_t a_length, struct Coordinates a_location)
{
	size_t row = a_location.m_row;
	size_t column = a_location.m_column;

	if((row <= m_height) && (column + (a_length - 1) <= m_width))
	{
		for(size_t i = 0; i < a_length; ++i)
		{
			if(m_board[row * m_width + column + i] == ' ')
			{
				return true;
			}
		}	
	}

	return false;
}

bool Board::check_vertical_vailidity(size_t a_length, struct Coordinates a_location)
{
	size_t row = a_location.m_row;
	size_t column = a_location.m_column;

	if((row + (a_length - 1) <= m_height) && (column <= m_width))	
	{
		for(size_t i = 0; i < a_length; ++i)
		{
			if(m_board[(row + i) * m_width + column] == ' ')
			{
				return true;
			}
		}
	}

	return false;
}

bool Board::check_direction_vailidity(std::string a_name, char a_direction)
{
	bool orientation = m_cars.at(a_name).m_orientation;
	if(orientation && (a_direction == 'l' || a_direction == 'r'))
	{
		return true;
	}
	else if(!orientation && (a_direction == 'd' || a_direction == 'u'))
	{
		return true;
	}

	return false;
	
}

bool Board::check_victory(size_t a_length, struct Coordinates a_location)
{
	size_t row = a_location.m_row;
	size_t column = a_location.m_column;

	if((row == m_height / 2) && (column + a_length - 1) == m_width)
	{
		return true;
	}

	return false;
}

Coordinates Board::get_new_location(std::string a_name, char a_direction)
{

	Coordinates newLocation = m_cars.at(a_name).m_location;
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

void Board::set_car_location(std::string a_name, struct Coordinates newLocation)
{
	m_cars.at(a_name).m_location.m_row = newLocation.m_row;
	m_cars.at(a_name).m_location.m_column = newLocation.m_column;
}


void Board::change_location_on_board(std::string a_name, char a_direction)
{
	bool orientation = m_cars.at(a_name).m_orientation;
	size_t row = m_cars.at(a_name).m_location.m_row;
	size_t column = m_cars.at(a_name).m_location.m_column;
	size_t length = m_cars.at(a_name).m_length;

	if(orientation) 
	{
		if(a_direction == 'l')
		{
			m_board[row * m_width + (column + length - 1)] = ' ';
			m_board[row * m_width + column - 1] = a_name[0];
		}
		if(a_direction == 'r')
		{
			m_board[row * m_width + column] = ' ';
			m_board[row * m_width + column + length] = a_name[0];
		}
	}
	else
	{
		if(a_direction == 'd')
		{
			m_board[row * m_width + column] = ' ';
			m_board[(row + length) * m_width + column] = a_name[0];
		}
		if(a_direction == 'u')
		{
			m_board[(row + length -1) * m_width + column] = ' ';
			m_board[(row - 1) * m_width + column] = a_name[0];
		}	
	}
}

} // namespace game

