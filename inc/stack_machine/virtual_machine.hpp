#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include <cstddef>
#include <vector>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "memory.hpp"
#include "controller.hpp"
//#include "stdin.hpp"
//#include "stdout.hpp"


namespace mng
{

class VirtualMachine
{
public:
	VirtualMachine(Stack<unsigned long>* a_numStack, 
					Stack<act::Instruction*>* m_ptrStack, Memory* a_memory, Controller* a_controller);
	~VirtualMachine();

	void run();

private:
	Stack<unsigned long>* m_numStack;
	Stack<act::Instruction*>* m_ptrStack;
	Memory* m_memory;
	Controller* m_controller;
};

}//namespace mng


#endif//VIRTUAL_MACHINE_HPP