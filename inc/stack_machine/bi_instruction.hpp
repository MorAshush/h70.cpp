#ifndef BI_INSTRUCTION_HPP
#define BI_INSTRUCTION_HPP

#include "instruction_base.hpp"
#include "bus.hpp"

namespace act
{

class BiInstruction: public Instruction
{
public:
	virtual int execute(Bus& a_bus);

protected:
	virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second) = 0;
};

}//namespace act



#endif // BI_INSTRUCTION_HPP