#ifndef OUTNUM_HPP
#define OUTNUM_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class OutNum: public Instruction
{
public:
    OutNum();
    ~OutNum();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_outnum();

}//namespace act


#endif//OUTNUM_HPP