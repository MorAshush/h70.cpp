#ifndef OR_HPP
#define OR_HPP

#include <string>

#include "instruction_base.hpp"
#include "bus.hpp"
#include "stack.hpp"
#include "controller.hpp"


namespace act
{

class Or: public Instruction
{
public:
    Or();
    ~Or();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_or();

}//namespace act


#endif//OR_HPP