#include "push.hpp"

namespace act
{

const std::string Push::NAME = "PUSH";

Push::Push()
{
}

Push::~Push()
{
}

int Push::execute(Bus& a_bus)
{
	++*(a_bus.controller());
		
	return 1;
}

Instruction* create_push()
{
	return new Push;
}

}//namespace act