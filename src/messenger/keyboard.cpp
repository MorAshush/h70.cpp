#include <cstdio>
#include <iostream>

#include "keyboard.hpp"
#include "text_input.hpp"


namespace in
{

Keyboard::Keyboard()
: TextInput()
{
}

std::string Keyboard::recieve()
{
	std::string data;

	std::cout << "type your message:\n";
	std::getline(std::cin, data);

	return data; 
}

}//namespace in
