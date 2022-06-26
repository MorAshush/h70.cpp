#include <cstddef>
#include <vector>
#include <iterator>

#include "memory.hpp"
#include "segmentation_fault.hpp"

namespace mng
{

Memory::Memory(size_t a_codeSize, size_t a_dataSize)
{
    m_code.reserve(a_codeSize);
    m_dataSegment.reserve(a_dataSize);
}

Memory::~Memory()
{

}

void Memory::set_instructions(std::vector<unsigned long> const& a_code)
{
    m_code = a_code;
}

std::vector<unsigned long> const& Memory::get_instructions() const
{
    return m_code;
}

unsigned long Memory::operator[](size_t a_address) const
{
    if(a_address >= m_code.size())
    {
        if(a_address >= m_code.size())
        {
            throw expt::SegmentationFaultErr("operator []", "invalid memory access. out of range");
        }
    }

    return m_code[a_address];
}

/*
std::function<void()> const& instruction_func(size_t a_address) const
{
    if(a_address >= m_code->size())
    {
        throw expt::SegmentationFaultErr("instruction_func", "invalid memory access. out of range");
    }

    return m_code[a_address];
}


size_t Memory::instruction_address(std::function<void()>* a_functionPtr)
{
    auto it = m_code.begin();
    auto end = m_code.end();
    size_t instructionAddress = 0;

    while(it != end)
    {
        if(*it == a_functionPtr)
        {
            return instructionAddress;
        }

        ++instructionAddress;
        ++it;
    }

    return -1;
}
*/

unsigned long Memory::get_data(size_t a_address) const
{
    if(a_address >= m_dataSegment.size())
    {
        throw expt::SegmentationFaultErr("get_data", "invalid memory access. out of range");
    }
    
    return m_dataSegment[a_address];
}

void Memory::set_data(size_t a_address, unsigned long a_data)
{
    if(a_address >= m_dataSegment.size())
    {
        throw expt::SegmentationFaultErr("get_data", "invalid memory access. out of range");
    }
    
    m_dataSegment[a_address] = a_data;
}

}//namespace mng
