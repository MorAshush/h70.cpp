#ifndef BINARY_JMP_INSTRUCTION_HPP
#define BINARY_JMP_INSTRUCTION_HPP

#include "instruction_base.hpp"
#include "bus.hpp"

namespace act
{

class BinaryJmpInstruction: public Instruction
{
public:
	virtual int execute(Bus& a_bus);

protected:
	virtual bool compare_func(unsigned long a_first, unsigned long a_second) = 0;
};

}//namespace act



#endif // BINARY_JMP_INSTRUCTION_HPP