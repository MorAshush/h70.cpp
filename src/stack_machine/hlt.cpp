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

Instruction* create_hlt(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Hlt;
}

}//namespace act