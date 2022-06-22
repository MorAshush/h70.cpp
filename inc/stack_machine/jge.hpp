#ifndef JGE_HPP
#define JGE_HPP

#include <string>

#include "binary_jmp_instruction.hpp"

namespace act
{

class Jge: public BinaryJmpInstruction
{
public:
    Jge();
    ~Jge();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jge();


}//namespace act


#endif//JGE_HPP