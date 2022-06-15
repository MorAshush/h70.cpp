#ifndef INSTRUCTION_POINTER_HPP
#define INSTRUCTION_POINTER_HPP

#include <cstddef>

#include "instruction_base.hpp"


namespace mng
{

class InstructionPtr
{

public:
	InstructionPtr(act::Instruction* a_ptr, size_t a_ptrIndex);

	act::Instruction* operator++();
	act::Instruction* operator--();
	act::Instruction* jump_to(size_t a_address);

	act::Instruction* get_ptr();
	size_t get_addr();

private:
	act::Instruction* m_current;
	size_t m_ptrAddress;

};

}//namespace mng










#endif //INSTRUCTION_POINTER_HPP