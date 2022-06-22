#ifndef COMPL_HPP
#define COMPL_HPP

#include <string>

#include "un_instruction.hpp"
#include "bus.hpp"


namespace act
{

class Compl: public UnInstruction
{
public:
    Compl();
    ~Compl();

public:
    virtual unsigned long actual_operation(unsigned long a_num, Bus& a_bus);    
    static const std::string NAME;

};

Instruction* create_compl();

}//namespace act


#endif//OMPL_HPP