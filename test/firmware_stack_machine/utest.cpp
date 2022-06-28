#include <string>
#include <stdlib.h>
#include <iostream>

#include "virtual_machine.hpp"
#include "parser.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "mapper.hpp"
#include "bus.hpp"
#include "error.hpp"


int main()
{

	container::Stack stNum(10);
	container::Stack stPtr(10);

	
	mng::Controller cn;

	mng::Memory me(100, 100);

	Bus bus;
	bus.set_bus(&stNum, &stPtr, &me, &cn);

	Mapper mapper(bus);

	Parser p(mapper);

/*	char fileName[] = "stack_prog.txt";
	in::ProgramLoader fileLoader(fileName);
	std::string programString = fileLoader.load();
	std::cout << programString << '\n';
*/
	std::string s = "PUSH 10\n"
					"PUSH 20\n"
					"PUSH 30\n"
					"PUSH 40\n"
					"PUSH 50\n"
					"ADD\n"
					"ADD\n"
					"SUB\n"
					"AND\n"
					"HLT";

	std::list<std::string> actionsNames = p.parse(s, ' ');
	auto it = actionsNames.begin();
	auto end = actionsNames.end();

	std::cout << "list of names: \n";
	while(it != end)
	{
		std::cout << *it << " ,";
		++it;
	}
	std::cout << '\n';

	std::vector<int64_t> codeVec;

	try
	{
		codeVec = p.compile();
	}
	catch(const expt::Error& e)
	{
		std::cout << e << "\nexiting program...\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "code vector is: \n";
	for(auto i : codeVec)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	me.set_instructions(codeVec);

	mng::VirtualMachine vm(&stNum, &stPtr, &me, &cn);

	vm.run();
	return 0;
}