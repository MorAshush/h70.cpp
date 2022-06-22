#include "indirect_jmp.hpp"
#include "stack_template.hpp"
#include "popip.hpp"
#include "dropip.hpp"
#include "controller.hpp"

namespace act
{


int IndirectJmp::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	if(compare_func(first, second))
	{
		PopIP i;
		return i.execute(a_bus);
	}
	else
	{
		DropIP i;
		return i.execute(a_bus);
	}
}

}//namespace act