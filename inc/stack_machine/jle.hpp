#ifndef JLE_HPP
#define JLE_HPP

#include <string>

#include "binary_jmp_instruction.hpp"

namespace act
{

class Jle: public BinaryJmpInstruction
{
public:
    Jle();
    ~Jle();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jle();


}//namespace act


#endif//JLE_HPP