#ifndef PUSHIP_ARG_HPP
#define PUSHIP_ARG_HPP

#include <string>
#include <cstddef>

#include "instruction_base.hpp"

namespace act
{
class PushIpArg: public Instruction
{
public:
	PushIpArg();

	virtual int execute(Bus& a_bus);
	void set_arg(std::string const& a_arg);

public:
    static const std::string NAME;

private:
	size_t m_arg;
};

PushIpArg* create_puship_arg();

}//namespace act





#endif//PUSHIP_ARG_HPP