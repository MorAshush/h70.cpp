#ifndef CAR_HPP
#define CAR_HPP

#include <cstddef>
#include <string>

namespace game
{

struct Coordinates
{
	size_t m_row;
	size_t m_column;
};

class Car
{
	friend class Board;

public:
	Car(std::string a_name, size_t a_length, bool a_orientation, struct Coordinates a_location);

	std::string  name();
	char length();
	bool orientation();

	void set_location(struct Coordinates a_location);

private:
	bool check_object_features(char* a_name, char a_length, struct Coordinates a_location, bool a_orientation);

private:
	std::string m_name;
	const size_t m_length;
	const int m_orientation;
	struct Coordinates m_location;
};






} // namespace game


#endif //CAR_HPP 