#include <cstring>
#include <stdlib.h>

#include "jmp_arg.hpp"
#include "controller.hpp"

namespace act
{

const std::string JmpArg::NAME = "JMPARG";

JmpArg::JmpArg()
{
}

void JmpArg::set_arg(std::string const& a_arg)
{
	char* cstring = new char[a_arg.length() + 1];
	strcpy(cstring, a_arg.c_str());

	m_arg = strtoul(cstring, NULL, 0);
	delete[] cstring;
}

int JmpArg::execute(Bus& a_bus)
{
	mng::Controller* c = a_bus.controller();
	c->jump_to(m_arg);

	++*c;
	return 1;
}

JmpArg* create_jmp_arg()
{
	return new JmpArg;
}

}//namespace act