#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cstddef>

#include "memory.hpp"
#include "instruction_base.hpp"
#include "instruction_pointer.hpp"

namespace mng
{

class Controller
{
public:
	Controller(act::Instruction* a_ptr, size_t a_ptrIndex);

	act::Instruction* inc_ptr();
	act::Instruction* dec_ptr();
	act::Instruction* jump_to(size_t a_address);

private:
	InstructionPtr m_ip;
};


}//namespace mng

#endif //CONTROLLER_HPP