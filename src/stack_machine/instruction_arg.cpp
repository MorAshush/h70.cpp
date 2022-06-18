#include <cstring>
#include <stdlib.h>

#include "instruction_arg.hpp"


namespace act
{

const std::string Arg::NAME = "ARG";

Arg::Arg()
{
}

void Arg::set_arg(std::string const& a_arg)
{
	char* cstring = new char[a_arg.length() + 1];
	strcpy(cstring, a_arg.c_str());

	m_arg = strtoul(cstring, NULL, 0);
	delete[] cstring;
}

int Arg::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	s->push(m_arg);

	++*(a_bus.controller());
		
	return 1;
}

Arg* create_arg()
{
	return new Arg;
}

}//namespace act