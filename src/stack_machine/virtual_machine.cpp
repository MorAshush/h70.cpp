#include <iostream>

#include "virtual_machine.hpp"
#include "bus.hpp"
#include "error.hpp"

namespace mng
{

VirtualMachine::VirtualMachine(container::Stack<unsigned long>* a_numStack, container::Stack<size_t>* m_ptrStack,
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
	Bus bus;
	bus.set_bus(m_numStack, m_ptrStack, m_memory, m_controller);
	size_t counter = 0;
	while(true)
	{
		size_t address = m_controller->ip();

		try
		{
			act::Instruction* instructionPtr = m_memory->instruction_ptr(address);

			int result = instructionPtr->execute(bus);

			if(!result)
			{
				break;
			}
			std::cout << "instruction number: " << counter << '\n';

			m_numStack->print();
			std::cout << '\n';
			++counter;
		}
		catch(const expt::Error& e)
		{
			std::cout << e << '\n';
			break;
		}
	}
}

}//namespace mng