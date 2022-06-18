#include <string>
#include <stdlib.h>

#include "virtual_machine.hpp"
#include "instruction_base.hpp"
#include "parser.hpp"
#include "factory.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "mapper.hpp"
#include "grammar.hpp"


int main()
{

	container::Stack<unsigned long> stNum(10);
	container::Stack<act::Instruction*> stPtr(10);
	
	mng::Controller cn;
	mng::Memory me(100, 100);
	Grammar grammar;
	Parser p(grammar);

	std::string s = "PUSH 10\n"
					"PUSH 30\n"
					"IN\n"
					"IN\n"
					"OUT\n"
					"DROP\n"
					"NOP\n"
					"LOAD\n"
					"PUSH 50\n"
					"HLT";

	std::list<std::string> actionsNames = p.parse(s, ' ');
	std::vector<act::Instruction*> v;

	Factory factory(grammar);
	try
	{
		v = factory.create(actionsNames, &stNum, &cn, &me);
	}
	catch(const expt::Error& e)
	{
		std::cout << e << "\nexiting program...\n";
		exit(EXIT_FAILURE);
	}

	me.set_instructions(v);

	mng::VirtualMachine vm(&stNum, &stPtr, &me, &cn);

	vm.run();
	return 0;
}