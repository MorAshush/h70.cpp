#ifndef ADD_HPP
#define ADD_HPP

#include <string>

#include "bi_instruction.hpp"

namespace act
{

class Add: public BiInstruction
{
public:
    Add();
    ~Add();

public:
    virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second);    
    static const std::string NAME;
};

Instruction* create_add();


}//namespace act


#endif//ADD_HPP
