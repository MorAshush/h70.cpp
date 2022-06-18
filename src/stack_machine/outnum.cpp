#include <iostream>

#include "outnum.hpp"


namespace act
{

const std::string OutNum::NAME = "OUTNUM";

OutNum::OutNum()
: m_stack(a_stack)
, m_controller(a_controller)
{
}

OutNum::~OutNum()
{
}

int OutNum::execute()
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long top = s->pop();

	std::cout << top << '\n';

	++*(a_bus.controller());

	return 1;
}

Instruction* create_outnum()
{
	return new OutNum;
}

}//namespace act
