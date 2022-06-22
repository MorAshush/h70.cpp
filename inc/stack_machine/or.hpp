#ifndef OR_HPP
#define OR_HPP

#include <string>

#include "bi_instruction.hpp"


namespace act
{

class Or: public BiInstruction
{
public:
    Or();
    ~Or();

public:
    virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second);    
    static const std::string NAME;
};

Instruction* create_or();

}//namespace act


#endif//OR_HPP