#include <iostream>

#include "virtual_machine.hpp"
#include "bus.hpp"
#include "error.hpp"

namespace mng
{

VirtualMachine::VirtualMachine(Stack<unsigned long>* a_numStack, Stack<act::Instruction*>* m_ptrStack,
													 Memory* a_memory, Controller* a_controller)
: m_numStack(a_numStack)
, m_ptrStack(m_ptrStack)
, m_memory(a_memory)
, m_controller(a_controller)
{
}

VirtualMachine::~VirtualMachine()
{
}

void VirtualMachine::run()
{
	Bus bus(m_numStack, m_ptrStack, m_memory, m_controller);
	while(true)
	{
		size_t address = m_controller->ip();
		
		try
		{
			m_numStack->print();
			act::Instruction* instructionPtr = m_memory->instruction_ptr(address);

			int result = instructionPtr->execute(bus);

			if(!result)
			{
				break;
			}
		}
		catch(const expt::Error& e)
		{
			std::cout << e << '\n';
			break;
		}
	}
}

}//namespace mng