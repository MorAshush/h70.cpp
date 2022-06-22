#include "je.hpp"


namespace act
{

const std::string Je::NAME = "JE";

Je::Je()
{
}

Je::~Je()
{
}

bool Je::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first == a_second;
}

Instruction* create_je()
{
	return new Je;
}


}//namespace act