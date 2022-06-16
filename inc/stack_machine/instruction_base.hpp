#ifndef INSTRUCTION_BASE_HPP
#define INSTRUCTION_BASE_HPP

#include <string>

namespace act
{

//abstract pure class
class Instruction
{
public:

    virtual ~Instruction(); 

    virtual void execute() = 0;
};

}//namespace act















#endif //INSTRUCTION_BASE_HPP