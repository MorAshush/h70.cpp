#ifndef NOP_HPP
#define NOP_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"
//#include "bus.hpp"


namespace act
{

class Nop: public Instruction
{
public:
    Nop(mng::Controller* a_controller);
    ~Nop();

    virtual void execute();

public:
    static const std::string NAME;

private:
    mng::Controller* m_controller;
};

Instruction* create_nop(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//NOP_HPP