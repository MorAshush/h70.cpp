#ifndef NOP_HPP
#define NOP_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"


namespace act
{

class Nop: public Instruction
{
public:
    Nop();
    ~Nop();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_nop();

}//namespace act


#endif//NOP_HPP