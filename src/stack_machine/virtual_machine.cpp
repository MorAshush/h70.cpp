#include <iostream>

#include "virtual_machine.hpp"
//#include "error.hpp"

namespace mng
{

VirtualMachine::VirtualMachine(container::Stack* a_stack, Memory* a_memory, Controller* a_controller)
: m_stack(a_stack)
, m_memory(a_memory)
, m_controller(a_controller)
{
}

VirtualMachine::~VirtualMachine()
{
}

void VirtualMachine::run()
{
	for(size_t i = 0; i < 5; ++i)
	{
		m_stack->print();

		size_t address = m_controller->ip();
		std::cout << "current ip is : " << address << '\n';
		act::Instruction* instructionPtr = m_memory->instruction_ptr(address);

			m_controller->execute_instruction(instructionPtr);

/*		catch(Error* e)
		{
			break;
		}*/
	}
}

}//namespace mng