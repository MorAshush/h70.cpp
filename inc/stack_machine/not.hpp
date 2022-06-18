#ifndef NOT_HPP
#define NOT_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class Not: public Instruction
{
public:
    Not();
    ~Not();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_not();

}//namespace act


#endif//NOT_HPP