#ifndef HLT_HPP
#define HLT_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"


namespace act
{

class Hlt: public Instruction
{
public:
    Hlt();

    virtual void execute();

public:
    static const std::string NAME;
  
};

Instruction* create_hlt(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//HLT_HPP