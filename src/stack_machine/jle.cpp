#include "jle.hpp"


namespace act
{

const std::string Jle::NAME = "JL";

Jle::Jle()
{
}

Jle::~Jle()
{
}

bool Jle::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first <= a_second;
}

Instruction* create_jle()
{
	return new Jle;
}


}//namespace act