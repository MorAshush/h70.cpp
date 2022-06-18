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

int Xor::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	s->push(first ^ second);

	++*(a_bus.controller());
	
	return 1;
}

Instruction* create_xor()
{
	return new Xor;
}

}//namespace act