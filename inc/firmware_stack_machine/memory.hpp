#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstddef>
#include <vector>
#include <functional>


namespace mng
{
class Memory
{
public:
    Memory(size_t a_codeSize, size_t a_dataSize);
    ~Memory();
    
    size_t size() const;

    void set_instructions(std::vector<unsigned long> const& a_code);
    std::vector<unsigned long> const& get_instructions() const;
    unsigned long operator[](size_t a_address) const;

//    std::function<void()> const& instruction_func(size_t a_address) const;

//    size_t instruction_address(std::function<void()> a_functionPtr);

    unsigned long get_data(size_t a_address) const;
    void set_data(size_t a_address, unsigned long a_data);

private:
    std::vector<unsigned long> m_code;
    std::vector<unsigned long> m_dataSegment;
};

}//namespace mng




#endif //MEMORY_HPP