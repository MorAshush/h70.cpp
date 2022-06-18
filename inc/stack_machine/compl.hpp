#ifndef COMPL_HPP
#define COMPL_HPP

#include <string>

#include "instruction_base.hpp"
//#include "stack_template.hpp"
//#include "controller.hpp"


namespace act
{

class Compl: public Instruction
{
public:
    Compl();
    ~Compl();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;

};

Instruction* create_compl();

}//namespace act


#endif//OMPL_HPP