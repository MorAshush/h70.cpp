#ifndef ADD_HPP
#define ADD_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
//#include "controller.hpp"



namespace act
{

class Add: public Instruction
{
public:
    Add(container::Stack* a_stack/*, Controller* a_controller*/);

    virtual std::string const& op_code() const;

    // returns a value to inc the ip by
    virtual int execute();

private:
    container::Stack* m_stack;
//    Controller* m_controller;
    std::string m_opCode;
};

}//namespace act


#endif//ADD_HPP
