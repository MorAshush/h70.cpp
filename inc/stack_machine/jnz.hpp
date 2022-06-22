#ifndef JNZ_HPP
#define JNZ_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Jnz: public Instruction
{
public:
    Jnz();
    ~Jnz();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_jnz();

}//namespace act


#endif//JNZ_HPP