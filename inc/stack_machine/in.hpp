#ifndef IN_HPP
#define IN_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class In: public Instruction
{
public:
    In();
    ~In();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_in();

}//namespace act


#endif//IN_HPP