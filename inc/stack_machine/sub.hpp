#ifndef SUB_HPP
#define SUB_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class Sub: public Instruction
{
public:
    Sub();
    ~Sub();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_sub();

}//namespace act


#endif//SUB_HPP