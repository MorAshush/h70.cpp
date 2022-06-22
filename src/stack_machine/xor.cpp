#include "xor.hpp"

namespace act
{

const std::string Xor::NAME = "XOR";

Xor::Xor()
{
}

Xor::~Xor()
{
}

unsigned long Xor::actual_operation(unsigned long a_first, unsigned long a_second)
{
	return a_first ^ a_second;
}

Instruction* create_xor()
{
	return new Xor;
}

}//namespace act