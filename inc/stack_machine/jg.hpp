#ifndef JG_HPP
#define JG_HPP

#include <string>

#include "binary_jmp_instruction.hpp"

namespace act
{

class Jg: public BinaryJmpInstruction
{
public:
    Jg();
    ~Jg();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jg();


}//namespace act


#endif//JG_HPP