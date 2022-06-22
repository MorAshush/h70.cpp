#ifndef UN_INSTRUCTION_HPP
#define UN_INSTRUCTION_HPP

#include "instruction_base.hpp"
#include "bus.hpp"

namespace act
{

class UnInstruction: public Instruction
{
public:
	virtual int execute(Bus& a_bus);

protected:
	virtual unsigned long actual_operation(unsigned long a_num, Bus& a_bus) = 0;
};

}//namespace act



#endif // UN_INSTRUCTION_HPP