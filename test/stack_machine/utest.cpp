#include <string>

#include "virtual_machine.hpp"
#include "instruction_base.hpp"
#include "parser.hpp"
#include "factory.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "mapper.hpp"
#include "grammar.hpp"


int main()
{

	container::Stack st(20);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	
	mng::Controller cn;
	mng::Memory me(100);
	Grammar grammar;
	Parser p(grammar);

	std::string s = "SUB\n"
					"PUSH 5\n"
					"AND\n"
					"ADD\n"
					"NOP\n"
					"LOAD\n"
					"HLT";

	std::list<std::string> actionsNames = p.parse(s, ' ');


	Factory factory(grammar);
	std::vector<act::Instruction*> v = factory.create(actionsNames, &st, &cn, &me);

	me.set_instructions(v);

	mng::VirtualMachine vm(&st, &me, &cn);

	vm.run();
	return 0;
}