#include <iostream>

#include "puship.hpp"


namespace act
{

const std::string PushIP::NAME = "PUSHIP";

PushIP::PushIP()
{
}

PushIP::~PushIP()
{
}

int PushIP::execute(Bus& a_bus)
{
	++*(a_bus.controller());

	return 1;
}

Instruction* create_puship()
{
	return new PushIP();
}

}//namespace act
