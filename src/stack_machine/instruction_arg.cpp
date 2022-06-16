#include <cstring>
#include <stdlib.h>

#include "instruction_arg.hpp"


namespace act
{

const std::string Arg::NAME = "ARG";

Arg::Arg(container::Stack* a_stack, mng::Controller* a_controller)
: m_arg()
, m_stack(a_stack)
, m_controller(a_controller)
{
}

void Arg::set_arg(std::string const& a_arg)
{
	char* cstring = new char[a_arg.length() + 1];
	strcpy(cstring, a_arg.c_str());

	m_arg = strtoul(cstring, NULL, 0);
	delete[] cstring;
}

void Arg::execute()
{
	m_stack->push(m_arg);

	++m_controller;
}

Arg* create_arg(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Arg(a_stack, a_controller);
}

}//namespace act