#ifndef JE_HPP
#define JE_HPP

#include <string>

#include "binary_jmp_instruction.hpp"

namespace act
{

class Je: public BinaryJmpInstruction
{
public:
    Je();
    ~Je();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_je();


}//namespace act


#endif//JE_HPP