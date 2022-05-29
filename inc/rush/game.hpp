#ifndef GAME_HPP
#define GAME_HPP


#include <vector>
#include <cstddef>
#include <string>

#include "board.hpp"

namespace game
{

namespace implementation_details
{
	bool is_name_valid(std::string a_name);
	bool is_length_valid(size_t a_length);
	bool is_orientation_valid(int a_orientation);
	bool is_direction_valid(char a_direction);

}

//struct Coordinates;

class Game
{

public:
	Game(const char* a_levelPath);

	void start();



private:
	Board m_board;
};


}//namespace game





#endif //GAME_HPP