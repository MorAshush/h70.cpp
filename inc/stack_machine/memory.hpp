#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstddef>
#include <vector>

#include "instruction_base.hpp"

namespace mng
{
class Memory
{
public:
    Memory(size_t a_memorySize, std::vector<act::Instruction*> const& m_instructionSegment);

    size_t size() const;
    long* data_segment_ptr() const;

    const act::Instruction* get_instruction(size_t a_address) const;
    act::Instruction* get_instruction(size_t a_address);

    long get_data(size_t a_address) const;
    void set_data(size_t a_address, long a_data);

    bool is_instruction_address_valid(size_t a_address) const;
    bool is_data_address_valid(size_t a_address) const;


private:
    size_t m_size;
    std::vector<act::Instruction*> m_instructionSegment;
    long* m_dataSegment;
};

}//namespace mng










#endif //MEMORY_HPP