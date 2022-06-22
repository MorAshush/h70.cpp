#include "sub.hpp"


namespace act
{

const std::string Sub::NAME = "SUB";

Sub::Sub()
{
}

Sub::~Sub()
{
}

unsigned long Sub::actual_operation(unsigned long a_first, unsigned long a_second)
{
	return a_first - a_second;
}

Instruction* create_sub()
{
	return new Sub;
}

}//namespace act
