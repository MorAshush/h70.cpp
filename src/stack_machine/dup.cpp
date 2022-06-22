#include "dup.hpp"
#include "stack_template.hpp"

namespace act
{

const std::string Dup::NAME = "DUP";

Dup::Dup()
{
}

Dup::~Dup()
{
}

unsigned long Dup::actual_operation(unsigned long a_num, Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	s->push(a_num);

	return a_num;
}

Instruction* create_dup()
{
	return new Dup;
}

}//namespace act
