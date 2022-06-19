#ifndef INSTRUCTION_ARG_HPP
#define INSTRUCTION_ARG_HPP

#include <string>

#include "instruction_base.hpp"

namespace act
{
class Arg: public Instruction
{
public:
	Arg();

	virtual int execute(Bus& a_bus);
	void set_arg(std::string const& a_arg);

public:
    static const std::string NAME;

private:
	unsigned long m_arg;
};

Arg* create_arg();

}//namespace act





#endif//INSTRUCTION_ARG_HPP