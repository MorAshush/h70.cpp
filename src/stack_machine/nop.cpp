#include <iostream>

#include "nop.hpp"


namespace act
{

const std::string Nop::NAME = "NOP";

Nop::Nop()
{
}

Nop::~Nop()
{
}

int Nop::execute(Bus& a_bus)
{
	++*(a_bus.controller());

	return 1;
}

Instruction* create_nop()
{
	return new Nop;
}

}//namespace act