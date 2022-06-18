#ifndef PUSHIP_HPP
#define PUSHIP_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{

class PushIP: public Instruction
{
public:
    PushIP();
    ~PushIP();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;

};

Instruction* create_puship();

}//namespace act


#endif//PUSHIP_HPP