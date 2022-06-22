#include "load.hpp"
#include "memory.hpp"


namespace act
{

const std::string Load::NAME = "LOAD";

Load::Load()
{
}

Load::~Load()
{
}

unsigned long Load::actual_operation(unsigned long a_num, Bus& a_bus)
{
	mng::Memory* m = a_bus.memory();
	unsigned long data = m->get_data(a_num);

	return data;
}

Instruction* create_load()
{
	return new Load;
}

}//namespace act