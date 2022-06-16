#ifndef AND_HPP
#define AND_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class And: public Instruction
{
public:
    And(container::Stack* a_stack, mng::Controller* a_controller);
    ~And();

    // returns a value to inc the ip by
    virtual void execute();

public:
    static const std::string NAME;

private:
    container::Stack* m_stack;
    mng::Controller* m_controller;
};

Instruction* create_and(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//AND_HPP