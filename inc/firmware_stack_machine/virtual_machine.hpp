#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include <cstddef>
#include <vector>

#include "stack.hpp"
#include "memory.hpp"
#include "controller.hpp"


namespace mng
{

class VirtualMachine
{
public:
	VirtualMachine(container::Stack* a_numStack, container::Stack* m_ptrStack, Memory* a_memory, Controller* a_controller);
	~VirtualMachine();

	void run();

private:
	container::Stack* m_numStack;
	container::Stack* m_ptrStack;
	Memory* m_memory;
	Controller* m_controller;
};

}//namespace mng


#endif//VIRTUAL_MACHINE_HPP