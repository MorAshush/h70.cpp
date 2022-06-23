#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>

#include "coordinates.hpp"


namespace game
{


game::Coordinates::Coordinates(int a_row, int a_column)
: m_row(a_row)
, m_column(a_column)
{

}

}