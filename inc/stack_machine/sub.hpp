#ifndef SUB_HPP
#define SUB_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class Sub: public Instruction
{
public:
    Sub(container::Stack* a_stack, mng::Controller* a_controller);
    ~Sub();

    virtual void execute();

public:
    static const std::string NAME;

private:
    container::Stack* m_stack;
    mng::Controller* m_controller;
};

Instruction* create_sub(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//SUB_HPP