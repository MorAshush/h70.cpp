#ifndef INDIRECT_JMP_HPP
#define INDIRECT_JMP_HPP

#include "instruction_base.hpp"
#include "bus.hpp"

namespace act
{

class IndirectJmp: public Instruction
{
public:
	virtual int execute(Bus& a_bus);

protected:
	virtual bool compare_func(unsigned long a_first, unsigned long a_second) = 0;
};

}//namespace act



#endif // INDIRECT_JMP_HPP