
#include "virtual_machine.hpp"

namespace mng
{
	VirtualMachine::VirtualMachine(size_t a_memorySize)
	: m_stack(new container::Stack())
/*	, m_block(new Memory(a_memorySize))
	, m_ip(new InstructionPtr)
	, m_stdin(new StdIn)
	, m_stdOut(new StdOut)
*/	{

	}

	VirtualMachine::~VirtualMachine()
	{
/*		delete m_outputer;
		delete m_inputer;
		delete m_ip;
		delete m_block;
*/		delete m_stack;
	}
/*
	char VirtualMachine::recieve_input()
	{

	}

	int VirtualMachine::send_output(char a_char)
	{

	}

	void VirtualMachine::run()
	{
		while(true)
		{

		}
	}
*/
}//namespace mng