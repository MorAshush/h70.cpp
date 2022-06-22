#ifndef DROPIP_HPP
#define DROPIP_HPP

#include <string>

#include "instruction_base.hpp"


namespace act
{

class DropIP: public Instruction
{
public:
    DropIP();
    ~DropIP();

    virtual int execute(Bus& a_bus);

public:
    static const std::string NAME;
};

Instruction* create_dropip();

}//namespace act


#endif//DROPIP_HPP