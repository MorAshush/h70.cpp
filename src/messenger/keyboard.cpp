#include <cstdio>
#include <iostream>

#include "keyboard.hpp"


namespace in
{

Keyboard::Keyboard()
: TextInput()
{
}

std::string Keyboard::recieve()
{
	std::string data;
	std::string input;

	std::cout << "type in your message.\n";
	std::cout << "new line with enter. end your message with sending the word \"EOM\" seperatly\n";
	
	std::getline(std::cin, input);

	while(input != "EOM")
	{
		data += input;
		data += '\n';
		std::getline(std::cin, input);
	}

	return data; 
}

}//namespace in
