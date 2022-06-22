#include "jgi.hpp"


namespace act
{

const std::string Jgi::NAME = "JGI";

Jgi::Jgi()
{
}

Jgi::~Jgi()
{
}

bool Jgi::compare_func(unsigned long a_first, unsigned long a_second)
{
	return a_first > a_second;
}

Instruction* create_jgi()
{
	return new Jgi;
}


}//namespace act