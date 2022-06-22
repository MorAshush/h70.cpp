#ifndef SWAP_HPP
#define SWAP_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Swap: public Instruction
{
public:
    Swap();
    ~Swap();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_swap();

}//namespace act


#endif//SWAP_HPP