#ifndef SUB_HPP
#define SUB_HPP

#include <string>

#include "bi_instruction.hpp"

namespace act
{

class Sub: public BiInstruction
{
public:
    Sub();
    ~Sub();

public:
    virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second);    
    static const std::string NAME;
};

Instruction* create_sub();

}//namespace act


#endif//SUB_HPP