#include <iostream>
#include <string>

#include "screen.hpp"
#include "text_output.hpp"

namespace out
{
/*
Screen::Screen()
: TextOutput()
{

}
*/
void send(std::string const& a_text)
{
    std::cout << a_text;
}




}//namespace out


