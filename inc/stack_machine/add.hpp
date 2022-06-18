#ifndef ADD_HPP
#define ADD_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Add: public Instruction
{
public:
    Add();
    ~Add();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_add();

}//namespace act


#endif//ADD_HPP
