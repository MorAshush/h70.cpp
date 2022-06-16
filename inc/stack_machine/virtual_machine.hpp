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
	VirtualMachine(container::Stack* a_stack, Memory* a_memory, Controller* a_controller);
	~VirtualMachine();

	void run();

private:
	container::Stack* m_stack;
	Memory* m_memory;
	Controller* m_controller;
};

}//namespace mng












#endif//VIRTUAL_MACHINE_HPP