#ifndef JL_HPP
#define JL_HPP

#include <string>

#include "binary_jmp_instruction.hpp"

namespace act
{

class Jl: public BinaryJmpInstruction
{
public:
    Jl();
    ~Jl();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jl();


}//namespace act


#endif//JL_HPP