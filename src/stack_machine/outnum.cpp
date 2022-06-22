#include <iostream>

#include "outnum.hpp"


namespace act
{

const std::string OutNum::NAME = "OUTNUM";

OutNum::OutNum()
{
}

OutNum::~OutNum()
{
}

int OutNum::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long top = s->pop();

	std::cout << top << '\n';

	mng::Controller* c = a_bus.controller();
	++*c;
	return 1;
}

Instruction* create_outnum()
{
	return new OutNum;
}

}//namespace act
