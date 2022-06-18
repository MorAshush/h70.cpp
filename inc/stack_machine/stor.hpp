#ifndef STOR_HPP
#define STOR_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Stor: public Instruction
{
public:
    Stor();
    ~Stor();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_stor();

}//namespace act


#endif//STOR_HPP