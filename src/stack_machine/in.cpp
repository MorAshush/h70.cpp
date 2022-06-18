#include <iostream>

#include "in.hpp"


namespace act
{

const std::string In::NAME = "IN";

In::In(container::Stack* a_stack, mng::Controller* a_controller)
: m_stack(a_stack)
, m_controller(a_controller)
{
}

In::~In()
{
}

int In::execute(Bus& a_bus)
{
	std::cout << "enter a character to push to the stack\n";
	char c;

	std::cin >> c;

	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	s->push(c);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_in(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new In(a_stack, a_controller);
}

}//namespace act
