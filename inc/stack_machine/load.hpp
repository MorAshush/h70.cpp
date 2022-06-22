#ifndef LOAD_HPP
#define LOAD_HPP

#include <string>

#include "un_instruction.hpp"
#include "bus.hpp"


namespace act
{

class Load: public UnInstruction
{
public:
    Load();
    ~Load();

public:
    virtual unsigned long actual_operation(unsigned long a_num, Bus& a_bus);    
    static const std::string NAME;

};

Instruction* create_load();

}//namespace act


#endif//LOAD_HPP