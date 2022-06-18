#include "sub.hpp"


namespace act
{

const std::string Sub::NAME = "SUB";

Sub::Sub()
{
}

Sub::~Sub()
{
}

int Sub::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	long first = s->pop();
	long second = s->pop();

	s->push(first - second);

	++*(a_bus.controller());
		
	return 1;
}

Instruction* create_sub()
{
	return new Sub;
}

}//namespace act
