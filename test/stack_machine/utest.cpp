#include <string>
#include <stdlib.h>

#include "virtual_machine.hpp"
#include "instruction_base.hpp"
#include "parser.hpp"
#include "factory.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "grammar.hpp"


int main()
{

	container::Stack<unsigned long> stNum(10);
	container::Stack<size_t> stPtr(10);
	
	mng::Controller cn;
	mng::Memory me(100, 100);
	Grammar grammar;
	Parser p(grammar);

	std::string s = "PUSH 100\n"
					"PUSHIP 13\n"
					"PUSHIP 7\n"
					"POPIP\n"
					"DUP\n"
					"DUP\n"
					"DUP\n"
					"DUP\n"
					"DUP\n"
					"POPIP\n"
					"ADD\n"
					"ADD\n"
					"ADD\n"
					"ADD\n"
					"ADD\n"
					"HLT";

	std::list<std::string> actionsNames = p.parse(s, ' ');
	std::vector<act::Instruction*> v;

	Factory factory(grammar);
	try
	{
		v = factory.create(actionsNames);
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