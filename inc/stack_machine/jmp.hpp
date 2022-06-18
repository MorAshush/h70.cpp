#ifndef JMP_HPP
#define JMP_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Jmp: public Instruction
{
public:
    Jmp();
    ~Jmp();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_jmp();

}//namespace act


#endif//JMP_HPP