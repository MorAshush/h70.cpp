#include <cstddef>
#include <vector>
#include <iterator>

#include "memory.hpp"
#include "segmentation_fault.hpp"

namespace mng
{

Memory::Memory(size_t a_textSize, size_t a_dataSize)
: m_instructionSegment(a_textSize)
, m_dataAllocatedSize(a_dataSize)
, m_dataSegment(new unsigned long[a_dataSize])
{
}

Memory::~Memory()
{
    size_t numOfInstructions = m_instructionSegment.size();

    for(size_t i = 0; i < numOfInstructions; ++i)
    {
        delete m_instructionSegment[i];
    }

    delete[] m_dataSegment;
}

void Memory::set_instructions(std::vector<act::Instruction*> const& a_instructions)
{
    m_instructionSegment = a_instructions;
}

const act::Instruction* Memory::instruction_ptr(size_t a_address) const
{
    if(a_address >= m_instructionSegment.size())
    {
        throw expt::SegmentationFaultErr("instruction_ptr", "invalid memory access. out of range");
    }

    return m_instructionSegment[a_address];
}

act::Instruction* Memory::instruction_ptr(size_t a_address)
{
    if(a_address >= m_instructionSegment.size())
    {
        throw expt::SegmentationFaultErr("instruction_ptr", "invalid memory access. out of range");
    }

    return m_instructionSegment[a_address];
}

size_t Memory::instruction_address(act::Instruction* a_instructionPtr)
{
    std::vector<act::Instruction*>::iterator it = m_instructionSegment.begin();
    std::vector<act::Instruction*>::iterator end = m_instructionSegment.end();
    size_t instructionAddress = 0;

    while(it != end)
    {
        if(*it == a_instructionPtr)
        {
            return instructionAddress;
        }

        ++instructionAddress;
        ++it;
    }

    return -1;
}

unsigned long Memory::get_data(size_t a_address) const
{
    if(a_address >= m_dataAllocatedSize)
    {
        throw expt::SegmentationFaultErr("get_data", "invalid memory access. out of range");
    }
    
    return m_dataSegment[a_address];
}

void Memory::set_data(size_t a_address, unsigned long a_data)
{
    if(a_address >= m_dataAllocatedSize)
    {
        throw expt::SegmentationFaultErr("get_data", "invalid memory access. out of range");
    }
    
    m_dataSegment[a_address] = a_data;
}

}//namespace mng
