#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstddef>
#include <string>
#include <vector>
#include <map>

#include "car.hpp"

namespace game
{


class Board
{

public:

	Board();
	Board(size_t a_width, size_t a_height);

	bool place_object(std::string a_name, size_t a_length, bool a_orientation, struct Coordinates a_loctaion);
	bool move_object(std::string a_name, char a_direction);
	bool is_victory() const;

	void print();

private:
	size_t width() const;
	size_t height() const;
	bool check_horizontal_vailidity(size_t a_length, struct Coordinates a_loctaion) const;
	bool check_vertical_vailidity(size_t a_length, struct Coordinates a_loctaion) const;
	bool check_victory(size_t a_length, struct Coordinates a_loctaion) const;
	bool check_direction_vailidity(std::string a_name, char a_direction) const;
	Coordinates get_new_location(std::string a_name, char a_direction);
	void set_object_location(std::string a_name, struct Coordinates newLocation);
	void change_location_on_board(std::string a_name, char a_direction);

private:

	size_t m_width; 
	size_t m_height;
	std::vector<char> m_board;
	std::map<char, Car> m_cars;
};

}// namespace game



#endif //BOARD_HPP