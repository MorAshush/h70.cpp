#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include <cstddef>

#include "stack.hpp"
//#include "memory.hpp"
//#include "controller.hpp"
//#include "stdin.hpp"
//#include "stdout.hpp"


namespace mng
{

class VirtualMachine
{
public:
	VirtualMachine(size_t a_memorySize);
	~VirtualMachine();

	char recieve_input();
	int send_output(char a_char);

	void run();

private:
	container::Stack* m_stack;
//	Memory* m_block;
//	InstructionPtr* m_ip;
//	StdIn* m_inputer;
//	StdOut* m_outputer;
};

}//namespace mng












#endif//VIRTUAL_MACHINE_HPP