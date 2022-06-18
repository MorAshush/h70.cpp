#include <iostream>

#include "out.hpp"


namespace act
{

const std::string Out::NAME = "OUT";

Out::Out()
{
}

Out::~Out()
{
}

int Out::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	char top = s->pop();

	std::cout << top << '\n';

	++*(a_bus.controller());

	return 1;
}

Instruction* create_out()
{
	return new Out;
}

}//namespace act
