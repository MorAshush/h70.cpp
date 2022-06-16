#ifndef PUSH_HPP
#define PUSH_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{

class Push: public Instruction
{
public:
    Push(mng::Controller* a_controller);
    ~Push();

    virtual void execute();

public:
    static const std::string NAME;

private:
    mng::Controller* m_controller;
};

Instruction* create_push(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//PUSH_HPP