#ifndef INSTRUCTION_BASE_HPP
#define INSTRUCTION_BASE_HPP

#include <string>

class Bus;

namespace act
{

//abstract pure class
class Instruction
{
public:

    virtual ~Instruction(); 

    virtual int execute(Bus& a_bus) = 0;
};

}//namespace act















#endif //INSTRUCTION_BASE_HPP