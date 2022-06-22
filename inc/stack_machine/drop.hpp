#ifndef DROP_HPP
#define DROP_HPP

#include <string>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
//#include "memory.hpp"



namespace act
{

class Drop: public Instruction
{
public:
    Drop();
    ~Drop();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;

};

Instruction* create_drop();

}//namespace act


#endif//DROP_HPP