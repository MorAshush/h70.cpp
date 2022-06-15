
#include "virtual_machine.hpp"

namespace mng
{
	VirtualMachine::VirtualMachine(size_t a_memorySize, std::vector<act::Instruction*> a_instructions)
	: m_stack(new container::Stack())
	, m_block(new Memory(a_memorySize, a_instructions))
	, m_controller(m_block->get_instruction(0), 0)
/*	, m_stdin(new StdIn)
	, m_stdOut(new StdOut)
*/	{
	}

	VirtualMachine::~VirtualMachine()
	{
/*		delete m_outputer;
		delete m_inputer;
		delete m_ip;
*/		delete m_block;
		delete m_stack;
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