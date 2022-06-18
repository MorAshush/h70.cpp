#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstddef>
#include <vector>

#include "segmentation_fault.hpp"
#include "instruction_base.hpp"

namespace mng
{
class Memory
{
public:
    Memory(size_t a_textSize, size_t a_dataSize);
    ~Memory();
    
    size_t size() const;

    void set_instructions(std::vector<act::Instruction*> const& a_instructions);

    const act::Instruction* instruction_ptr(size_t a_address) const;
    act::Instruction* instruction_ptr(size_t a_address);

    size_t instruction_address(act::Instruction* a_instructionPtr);

    unsigned long get_data(size_t a_address) const;
    void set_data(size_t a_address, unsigned long a_data);
/*
private:
    bool is_instruction_address_valid(size_t a_address) const;
    bool is_data_address_valid(size_t a_address) const;
*/

private:
    std::vector<act::Instruction*> m_instructionSegment;
    size_t m_dataAllocatedSize;
    unsigned long* m_dataSegment;
};

}//namespace mng










#endif //MEMORY_HPP