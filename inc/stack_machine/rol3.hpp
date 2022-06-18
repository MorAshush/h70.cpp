#ifndef ROL3_HPP
#define ROL3_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"



namespace act
{

class RolThree: public Instruction
{
public:
    RolThree();
    ~RolThree();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_rolThree();

}//namespace act


#endif//ROL3_HPP