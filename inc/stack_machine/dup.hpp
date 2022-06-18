#ifndef DUP_HPP
#define DUP_HPP

#include <string>

#include "instruction_base.hpp"
//#include "stack.hpp"
//#include "controller.hpp"
//#include "memory.hpp"



namespace act
{

class Dup: public Instruction
{
public:
    Dup();
    ~Dup();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_dup();

}//namespace act


#endif//DUP_HPP