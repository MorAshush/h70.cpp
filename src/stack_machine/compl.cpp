#include "compl.hpp"

namespace act
{

const std::string Compl::NAME = "COMPL";

Compl::Compl()
{
}

Compl::~Compl()
{
}

unsigned long Compl::actual_operation(unsigned long a_num, Bus& a_bus)
{
	unsigned long result = ~a_num;

	return result;
}

Instruction* create_compl()
{
	return new Compl;
}

}//namespace act