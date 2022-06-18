#ifndef HLT_HPP
#define HLT_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"


namespace act
{

class Hlt: public Instruction
{
public:
    Hlt();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
  
};

Instruction* create_hlt();

}//namespace act


#endif//HLT_HPP