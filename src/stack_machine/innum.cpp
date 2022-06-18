#include <iostream>

#include "innum.hpp"


namespace act
{

const std::string InNum::NAME = "INNUM";

InNum::InNum()
{
}

InNum::~InNum()
{
}

int InNum::execute(Bus& a_bus)
{
	std::cout << "enter a number to push to the stack\n";
	unsigned long num;

	std::cin >> num;
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	s->push(num);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_innum()
{
	return new InNum;
}

}//namespace act
