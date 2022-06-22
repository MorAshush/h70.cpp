#ifndef NOT_HPP
#define NOT_HPP

#include <string>

#include "un_instruction.hpp"
#include "bus.hpp"

namespace act
{

class Not: public UnInstruction
{
public:
    Not();
    ~Not();

public:
    virtual unsigned long actual_operation(unsigned long a_num, Bus& a_bus);    
    static const std::string NAME;
};

Instruction* create_not();

}//namespace act


#endif//NOT_HPP