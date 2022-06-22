#include "jg.hpp"


namespace act
{

const std::string Jg::NAME = "JG";

Jg::Jg()
{
}

Jg::~Jg()
{
}

bool Jg::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first > a_second;
}

Instruction* create_jg()
{
	return new Jg;
}


}//namespace act