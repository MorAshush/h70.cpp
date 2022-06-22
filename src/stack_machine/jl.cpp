#include "jl.hpp"


namespace act
{

const std::string Jl::NAME = "JL";

Jl::Jl()
{
}

Jl::~Jl()
{
}

bool Jl::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first < a_second;
}

Instruction* create_jl()
{
	return new Jl;
}


}//namespace act