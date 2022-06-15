#include <cstddef>
#include <vector>

#include "memory.hpp"

namespace mng
{

Memory::Memory(size_t a_memorySize, std::vector<act::Instruction*> const& a_instructions)
: m_size(a_memorySize)
, m_instructionSegment(a_instructions)
, m_dataSegment(new long[a_memorySize - a_instructions.size()])
{
}

size_t Memory::size() const
{
    return m_size;
}

long* Memory::data_segment_ptr() const
{
    return m_dataSegment;
}

const act::Instruction* Memory::get_instruction(size_t a_address) const
{
    return m_instructionSegment[a_address];
}

act::Instruction* Memory::get_instruction(size_t a_address)
{
    return m_instructionSegment[a_address];
}

long Memory::get_data(size_t a_index) const
{
    return m_dataSegment[a_index];
}

void Memory::set_data(size_t a_index, long a_data)
{
    m_dataSegment[a_index] = a_data;
}

}//namespace mng
