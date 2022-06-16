#ifndef LOAD_HPP
#define LOAD_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class Load: public Instruction
{
public:
    Load(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);
    ~Load();

    virtual void execute();

public:
    static const std::string NAME;

private:
    container::Stack* m_stack;
    mng::Controller* m_controller;
    mng::Memory* m_memory;
};

Instruction* create_load(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act


#endif//LOAD_HPP