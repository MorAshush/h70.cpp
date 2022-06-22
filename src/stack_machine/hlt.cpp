#include <iostream>
#include<stdlib.h>

#include "hlt.hpp"

namespace act
{

const std::string Hlt::NAME = "HLT";

Hlt::Hlt()
{
}

int Hlt::execute(Bus& a_bus)
{
	return 0;
}

Instruction* create_hlt()
{
	return new Hlt;
}

}//namespace act