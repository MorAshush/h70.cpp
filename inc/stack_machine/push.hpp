#ifndef PUSH_HPP
#define PUSH_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{

class Push: public Instruction
{
public:
    Push();
    ~Push();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_push();

}//namespace act


#endif//PUSH_HPP