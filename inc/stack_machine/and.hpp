#ifndef AND_HPP
#define AND_HPP

#include <string>

#include "bi_instruction.hpp"

namespace act
{

class And: public BiInstruction
{
public:
    And();
    ~And();

public:
    virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second);    
    static const std::string NAME;
};

Instruction* create_and();

}//namespace act


#endif//AND_HPP