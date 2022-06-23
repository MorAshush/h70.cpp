#ifndef JMP_ARG_HPP
#define JMP_ARG_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"


namespace act
{

class JmpArg: public Instruction
{
public:
    JmpArg();

    virtual int execute(Bus& a_bus);
    void set_arg(std::string const& a_arg);

public:
    static const std::string NAME;
    unsigned long m_arg;
  
};

JmpArg* create_jmp_arg();

}//namespace act


#endif//JMP_ARG_HPP