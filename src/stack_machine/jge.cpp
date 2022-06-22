#include "jge.hpp"


namespace act
{

const std::string Jge::NAME = "JGE";

Jge::Jge()
{
}

Jge::~Jge()
{
}

bool Jge::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first >= a_second;
}

Instruction* create_jge()
{
	return new Jge;
}


}//namespace act