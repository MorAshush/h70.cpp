#ifndef LOAD_HPP
#define LOAD_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Load: public Instruction
{
public:
    Load();
    ~Load();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;

};

Instruction* create_load();

}//namespace act


#endif//LOAD_HPP