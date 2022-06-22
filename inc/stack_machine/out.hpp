#ifndef OUT_HPP
#define OUT_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Out: public Instruction
{
public:
    Out();
    ~Out();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_out();

}//namespace act


#endif//OUT_HPP