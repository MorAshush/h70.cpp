#include <vector>
#include <iterator>
#include <map>
#include <cstddef>
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

bool Board::place_object(std::string a_name, size_t a_length, bool a_orientation, struct Coordinates a_location)
{
	if(a_orientation) 
	{
		if(check_horizontal_vailidity(a_length, a_location))
		{
			size_t row = a_location.m_row;
			size_t column = a_location.m_column;

			for(size_t i = 0; i < a_length; ++i)
			{
				m_board[row * m_width + column + i] = a_name[0];
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
				m_board[(row + i) * m_width + column] = a_name[0];
			}
		}
		else
		{
			return 0;
		}
	}
	
	Car newCar(a_name, a_length, a_orientation, a_location);
	m_cars.insert(std::pair<char, Car>(a_name[0], newCar));

	return 1;
}

bool Board::move_object(std::string a_name, char a_direction)
{
	Car car = m_cars.at(a_name[0]);
	if(car.is_valid_direction(a_direction)) //check_direction_vailidity(a_name, a_direction)
	{
		if(is_move_possible(car, a_direction))
		{
			car.move(a_direction);
			return 1;
		}
	}
	
	return 0;
}
/*
bool Board::move_object(std::string a_name, char a_direction)
{
	bool result = check_direction_vailidity(a_name, a_direction);
	if(result)
	{
		Coordinates newLocation = get_new_location(a_name, a_direction);
		if((newLocation.m_row <= m_height) && (newLocation.m_column <= m_width) && is_location_available(a_name, a_direction)) 
		{
			change_location_on_board(a_name, a_direction);
			set_object_location(a_name, newLocation);

			return 1;
		}
	}
	
	return 0;
}
*/
bool Board::is_victory() const
{
	char carsNames[] = {'Y', 'R', 'G', 'O', 'B', 'W'};

	for(size_t i = 0; i < std::strlen(carsNames); ++i)
	{
		if(m_cars.at(carsNames[i]).orientation())
		{
			bool result = check_victory(m_cars.at(carsNames[i]).length(), m_cars.at(carsNames[i]).location());
			if(result)
			{
				return true;
			}
		}
	}

	return false;
}

size_t Board::width() const
{
	return m_width;
}

size_t Board::height() const
{
	return m_height;
}

std::string Board::get_state()
{
	std::string state;

	for(size_t i = 0; i < width(); ++i)
	{
		state += "---";
	}

	state += '\n';

	for(size_t i = 0; i < height(); ++i)
	{
		state += '|';

		for(size_t j = 0; j < width(); ++j)
		{
			state += ' ';
			char carName = get_car_by_location(i, j);
			state += carName;
			state += ' ';
		}
		if(i != height()/2)
		{
			state += '|';
		}


		state += '\n';
	}
	
	return state;
}
/*
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
*/
bool Board::check_horizontal_vailidity(size_t a_length, struct Coordinates a_location) const
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

bool Board::check_vertical_vailidity(size_t a_length, struct Coordinates a_location) const
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


bool Board::check_victory(size_t a_length, struct Coordinates a_location) const
{
	size_t row = a_location.m_row;
	size_t column = a_location.m_column;

	if((row == m_height / 2) && (column + a_length - 1) == m_width)
	{
		return true;
	}

	return false;
}
/*
Coordinates Board::get_new_location(std::string a_name, char a_direction)
{

	Coordinates newLocation = m_cars.at(a_name[0]).location();
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

bool Board::is_location_available(std::string a_name, char a_direction)
{
	Car car = m_cars.at(a_name[0]);
	bool orientation = car.orientation();

	Coordinates location = car.location();
	size_t row = location.m_row;
	size_t column = location.m_column;

	if(orientation && a_direction == 'r')
	{
		if((m_board[row * m_width + (column + car.length())] == ' '))
		{
			return true;
		}
	}
	else if(orientation && a_direction == 'l')
	{
		if(m_board[row * m_width + (column - 1)] == ' ')
		{
			return true;
		}
	}
	else if(!orientation && a_direction == 'u')
	{
		if(m_board[(row - 1) * m_width + column] == ' ')
		{
			return true;
		}
	}
	else if(!orientation && a_direction == 'd')
	{
		if(m_board[(row + car.length()) * m_width + column] == ' ')
		{
			return true;
		}
	}

	return false;
}

void Board::set_object_location(std::string a_name, struct Coordinates newLocation)
{
	m_cars.at(a_name[0]).set_location(newLocation); 
}
*/

void Board::change_location_on_board(std::string a_name, char a_direction)
{
	bool orientation = m_cars.at(a_name[0]).orientation();
	size_t row = m_cars.at(a_name[0]).location().m_row;
	size_t column = m_cars.at(a_name[0]).location().m_column;
	size_t length = m_cars.at(a_name[0]).length();

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

bool Board::is_move_possible(Car a_car, char a_direction)
{
	size_t row = a_car.location().m_row;
	size_t column = a_car.location().m_column;

	if(a_car.orientation() && a_direction == 'l')
	{
		if(!is_cell_free(row, column - 1))
		{
			return false;
		}
	}
	else if(a_car.orientation() && a_direction == 'r')
	{
		if(!is_cell_free(row, column + a_car.length()))
		{
			return false;
		}
	}
	else if(!a_car.orientation() && a_direction == 'u')
	{
		if(!is_cell_free(row - 1, column))
		{
			return false;
		}
	}
	else if(!a_car.orientation() && a_direction == 'd')
	{
		if(!is_cell_free(row + a_car.length(), column))
		{
			return false;
		}
	}
	
	return true;
}

bool Board::is_cell_free(size_t a_row, size_t a_column)
{
	std::map<char, Car>::iterator current = m_cars.begin();
	std::map<char, Car>::iterator end = m_cars.end();

	while(current != end)
	{
		if(current->second.location().m_row == a_row && current->second.location().m_column == a_column)
		{
			return false;
		}

		++current;	
	}

	return true;
}

char Board::get_car_by_location(size_t a_row, size_t a_column)
{
	std::map<char, Car>::iterator current = m_cars.begin();
	std::map<char, Car>::iterator end = m_cars.end();

	while(current != end)
	{
		if(current->second.location().m_row == a_row && current->second.location().m_column == a_column)
		{
			return current->second.name()[0];
		}

		++current;	
	}

	return ' ';
}

} // namespace game

