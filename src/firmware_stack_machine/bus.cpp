#include "bus.hpp"
#include "stack.hpp"
#include "memory.hpp"
#include "controller.hpp"


Bus::Bus()
{

}

Bus::~Bus()
{

}

void Bus::set_bus(container::Stack* a_numStack, container::Stack* a_ptrStack, mng::Memory* a_memory, mng::Controller* a_controller)
{
	m_numStack = a_numStack;
	m_ptrStack = a_ptrStack;
	m_memory = a_memory;
	m_controller = a_controller;
}

container::Stack* Bus::numbers_stack() const
{
	return m_numStack;
}

container::Stack* Bus::pointers_stack() const
{
	return m_ptrStack;
}

mng::Memory* Bus::memory() const
{
	return m_memory;
}

mng::Controller* Bus::controller() const
{
	return m_controller;
}