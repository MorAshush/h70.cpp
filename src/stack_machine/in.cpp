#include <iostream>

#include "in.hpp"


namespace act
{

const std::string In::NAME = "IN";

In::In()
{
}

In::~In()
{
}

int In::execute(Bus& a_bus)
{
	std::cout << "enter a character to push to the stack\n";
	char c;

	std::cin >> c;

	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	s->push(c);

	mng::Controller* cont = a_bus.controller();
	++*cont;
	return 1;
}

Instruction* create_in()
{
	return new In;
}

}//namespace act
