#ifndef ADD_HPP
#define ADD_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
//#include "memory.hpp"



namespace act
{

class Add: public Instruction
{
public:
    Add(container::Stack* a_stack, mng::Controller* a_controller);
    ~Add();

    virtual void execute();

public:
    static const std::string NAME;

private:
    container::Stack* m_stack;
    mng::Controller* m_controller;
};

Instruction* create_add(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//ADD_HPP