#ifndef DUP_HPP
#define DUP_HPP

#include <string>

#include "un_instruction.hpp"
#include "bus.hpp"


namespace act
{

class Dup: public UnInstruction
{
public:
    Dup();
    ~Dup();

public:
    virtual unsigned long actual_operation(unsigned long a_num, Bus& a_bus);    
    static const std::string NAME;
};

Instruction* create_dup();

}//namespace act


#endif//DUP_HPP