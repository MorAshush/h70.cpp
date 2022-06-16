#include <cstddef>
#include <vector>

#include "memory.hpp"

namespace mng
{

Memory::Memory(size_t a_memorySize)
: m_size(a_memorySize)
, m_instructionSegment()
, m_dataSegment(new long[a_memorySize])
{
}

Memory::~Memory()
{
    size_t numOfInstructions = m_instructionSegment.size();

    for(size_t i = 0; i < numOfInstructions; ++i)
    {
        delete m_instructionSegment[i];
    }
}

size_t Memory::size() const
{
    return m_size;
}

void Memory::set_instructions(std::vector<act::Instruction*> const& a_instructions)
{
    m_instructionSegment = a_instructions;
}

const act::Instruction* Memory::instruction_ptr(size_t a_address) const
{
    if(a_address >= m_instructionSegment.size())
    {
        //throw "invalid access to memory"-segmentation fault exception
    }

    return m_instructionSegment[a_address];
}

act::Instruction* Memory::instruction_ptr(size_t a_address)
{
    if(a_address >= m_instructionSegment.size())
    {
        //throw "invalid access to memory"-segmentation fault exception
    }

    return m_instructionSegment[a_address];
}

unsigned long Memory::get_data(size_t a_address) const
{
    if(a_address >= m_instructionSegment.size())
    {
        //throw "invalid access to memory"-segmentation fault exception
    }
    
    return m_dataSegment[a_address];
}

void Memory::set_data(size_t a_address, unsigned long a_data)
{
    if(a_address >= m_instructionSegment.size())
    {
        //throw "invalid access to memory"-segmentation fault exception
    }
    
    m_dataSegment[a_address] = a_data;
}

}//namespace mng
