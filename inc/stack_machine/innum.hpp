#ifndef INNUM_HPP
#define INNUM_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class InNum: public Instruction
{
public:
    InNum();
    ~InNum();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_innum();

}//namespace act


#endif//INNUM_HPP