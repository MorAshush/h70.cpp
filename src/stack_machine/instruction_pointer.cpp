#include <cstddef>

#include "instruction_pointer.hpp"

namespace mng
{


InstructionPtr::InstructionPtr(act::Instruction* a_ptr, size_t a_ptrIndex)
: m_current(a_ptr)
, m_ptrAddress(a_ptrIndex)
{
}

act::Instruction* InstructionPtr::operator++()
{
	++m_ptrAddress;
	return ++m_current;
}

act::Instruction* InstructionPtr::operator--()
{
	--m_ptrAddress;
	return --m_current;
}

act::Instruction* InstructionPtr::jump_to(size_t a_address)
{
	size_t delta = a_address - m_ptrAddress;
	
	m_current = m_current + delta;
	m_ptrAddress = a_address;

	return m_current;
}

act::Instruction* InstructionPtr::get_ptr()
{
	return m_current;
}

size_t InstructionPtr::get_addr()
{
	return m_ptrAddress;
}


}//namespace mng