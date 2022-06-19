#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include <cstddef>
#include <vector>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "memory.hpp"
#include "controller.hpp"


namespace mng
{

class VirtualMachine
{
public:
	VirtualMachine(container::Stack<unsigned long>* a_numStack, 
					container::Stack<act::Instruction*>* m_ptrStack, Memory* a_memory, Controller* a_controller);
	~VirtualMachine();

	void run();

private:
	container::Stack<unsigned long>* m_numStack;
	container::Stack<act::Instruction*>* m_ptrStack;
	Memory* m_memory;
	Controller* m_controller;
};

}//namespace mng


#endif//VIRTUAL_MACHINE_HPP