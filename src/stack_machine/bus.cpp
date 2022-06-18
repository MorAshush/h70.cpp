#include "bus.hpp"

Bus::Bus(container::Stack<unsigned long>* a_numStack, container::Stack<act::Instruction*>* m_ptrStack, mng::Memory* a_memory, mng::Controller* a_controller)
: m_numStack(a_numStack)
, m_ptrStack(m_ptrStack)
, m_memory(a_memory)
, m_controller(a_controller)
{

}

Bus::~Bus()
{

}

container::Stack<unsigned long>* Bus::numbers_stack() const
{
	return m_numStack;
}

container::Stack<act::Instruction*>* Bus::pointers_stack() const
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