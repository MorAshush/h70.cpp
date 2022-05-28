#include <vector>
#include <iterator>
#include <cstddef>
#include <cassert>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <iostream>

#include "game.hpp"
#include "board.hpp"

namespace game
{

Game::Game(const char* a_fileName)
: m_board() 
{
	char name;
	size_t length;
	int orientation;
	Coordinates location;

	std::filebuf buff;
	if(buff.open(a_fileName, std::ios::in))
	{
		std::istream is(&buff);
		while(is)
		{
			is>>name;
			is>>length;
			is>>orientation;
			is>>location.m_row;
			is>>location.m_column;

			if(implementation_details::is_name_valid(name) && implementation_details::is_length_valid(length) 
													&& implementation_details::is_orientation_valid(orientation))
			{
				m_board.place_car(name, length, orientation, location);
			}
		}
	}
	
	buff.close();
}


void Game::start()
{
	char input[2] = {0};

	std::cout << "Let's play RushHour!\n";
	std::cout << "type in the car's letter and first letter of direction(d-down, u-up, l-left. r-right)\n e.g. \"Yu\" for Yellow, Up\n ";
	std::cout << "type in '!' if you wish to quit game.\n";
	
	m_board.print();

	std::cout << "choose your move:\n";
	scanf("%s", input);

	while(!m_board.is_victory())
	{
		if(input[0] == '!')
		{
			std::cout << "exisiting game...\n";
			return;
		}

		if(implementation_details::is_name_valid(input[0]) && implementation_details::is_direction_valid(input[1]))
		{
			bool result = m_board.move_car(input[0], input[1]);
			if(!result)
			{
				std::cout << "your move is not possible, think again";
			}
			
			if(m_board.is_victory())
			{
				break;
			}
		}
		else
		{
			std::cout << "input is invalid, try again.\nCar's letter must be exisiting on board, direction can only be d, u, l, r.\n";
		}

		m_board.print();

		std::cout << "choose your move:\n";
		scanf("%s", input);
	} 

	std::cout << "Level completed. Good job!\n";

	return;
}

/*
void Game::start()
{
	char input[2] = {0};

	std::cout << "Let's play RushHour!\n";
	std::cout << "type in the car's letter and first letter of direction(d-down, u-up, l-left. r-right)\n e.g. \"Yu\" ";
	std::cout << "type in '!' if you wish to quit game.\n";
	
	m_board.print();

	std::cout << "choose your move:\n";
	scanf("%s", input);

	while(input[0] != '!')
	{
		if(implementation_details::is_name_valid(input[0]) && implementation_details::is_direction_valid(input[1]))
		{
			bool result = m_board.move_car(input[0], input[1]);
			if(!result)
			{
				std::cout << "your move is not possible, think again";
			}
		}
		else
		{
			std::cout << "input is invalid, try again.\nCar's letter must be exisiting on board, direction can only be d, u, l, r.\n";
		}

		if(m_board.is_victory())
		{
			std::cout << "Level completed. Good job!\n";
			break;
		}
		
		m_board.print();

		std::cout << "choose your move:\n";
		scanf("%s", input);
	} 

	return;
}
*/

bool implementation_details::is_name_valid(char a_name)
{
	if((a_name == 'Y' || a_name == 'O' || a_name == 'R' || a_name == 'G' || a_name == 'B' || a_name == 'W'))
	{
		return true;
	}

	return false;
}

bool implementation_details::is_length_valid(size_t a_length)
{
	if(a_length < 2 || a_length > 4)
	{
		return false;
	}

	return true;
}

bool implementation_details::is_orientation_valid(int a_orientation)
{
	if(a_orientation != 0 && a_orientation != 1)
	{
		return false;
	}

	return true;
}

bool implementation_details::is_direction_valid(char a_direction)
{
	if(a_direction == 'd' || a_direction == 'u' || a_direction == 'l' || a_direction == 'r')
	{
		return true;
	}

	return false;
}

}//namespace game