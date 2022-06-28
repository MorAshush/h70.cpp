#include <iostream>

#include "virtual_machine.hpp"
#include "bus.hpp"
#include "mapper.hpp"
#include "error.hpp"

namespace mng
{

VirtualMachine::VirtualMachine(container::Stack* a_numStack, container::Stack* m_ptrStack, Memory* a_memory, Controller* a_controller)
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
	Mapper maps(bus);
	auto operationsMap = maps.functions_map();

	size_t counter = 1;
	while(bus.is_active())
	{
		size_t address = bus.controller()->ip();
		int64_t	codeValue = m_memory->instruction_opcode(address);	
		try
		{
			std::cout << "instruction number: " << counter << '\n';
			std::cout << "instruction address: " << address << '\n';
			std::cout << "instruction opCode: " << codeValue << '\n';

			operationsMap[static_cast<opCode>(codeValue)]();

			m_numStack->print();
			std::cout << '\n';
		}
		catch(const expt::Error& e)
		{
			std::cout << e << '\n';
			break;
		}
		++counter;
		
	}
}

}//namespace mng