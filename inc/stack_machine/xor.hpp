#ifndef XOR_HPP
#define XOR_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class Xor: public Instruction
{
public:
    Xor();
    ~Xor();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_xor();

}//namespace act


#endif//XOR_HPP