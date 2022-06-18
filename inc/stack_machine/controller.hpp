#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cstddef>

#include "memory.hpp"
#include "instruction_base.hpp"
//#include "instruction_pointer.hpp"

namespace mng
{

class Controller
{
public:
	Controller();

	void operator++();
	void operator--();
	void jump_to(size_t a_address);

	size_t ip();

	int execute_instruction(act::Instruction* a_instruction);

private:
	size_t m_ip;
};


}//namespace mng

#endif //CONTROLLER_HPP