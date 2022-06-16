#ifndef INSTRUCTION_ARG_HPP
#define INSTRUCTION_ARG_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{
class Arg: public Instruction
{
public:
	Arg(container::Stack* a_stack, mng::Controller* a_controller);

	virtual void execute();
	void set_arg(std::string const& a_arg);

public:
    static const std::string NAME;

private:
	unsigned long m_arg;
	container::Stack* m_stack;
	mng::Controller* m_controller;
};

Arg* create_arg(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

}//namespace act





#endif//INSTRUCTION_ARG_HPP