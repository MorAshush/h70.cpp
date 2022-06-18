#ifndef AND_HPP
#define AND_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{

class And: public Instruction
{
public:
    And();
    ~And();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;

};

Instruction* create_and();

}//namespace act


#endif//AND_HPP