#include <iostream>

#include "screen.hpp"

namespace out
{

Screen::Screen()
: TextOutput()
{

}

void Screen::send(std::string const& a_text)
{
    std::cout << a_text;
}




}//namespace out


