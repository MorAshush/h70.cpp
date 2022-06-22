#include "jei.hpp"


namespace act
{

const std::string Jei::NAME = "JEI";

Jei::Jei()
{
}

Jei::~Jei()
{
}

bool Jei::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first == a_second;
}

Instruction* create_jei()
{
	return new Jei;
}


}//namespace act