#ifndef POPIP_HPP
#define POPIP_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "ip_stack.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{

class PopIP: public Instruction
{
public:
    PopIP();
    ~PopIP();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_popip();

}//namespace act


#endif//POPIP_HPP