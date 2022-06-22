#ifndef JZ_HPP
#define JZ_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Jz: public Instruction
{
public:
    Jz();
    ~Jz();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_jz();

}//namespace act


#endif//JZ_HPP