#include <iterator>

#include "mapper.hpp"
#include "functions.hpp"

Mapper::Mapper(Bus& a_bus)
{
/*	container::Stack* s = a_bus.numbers_stack();
	mng::Controller* c = a_bus.controller();
	mng::Memory* m = a_bus.memory();
*/
	m_opCodes["PUSH"] = PUSH;
	m_opCodes["ADD"] = ADD;
	m_opCodes["SUB"] = SUB;
	m_opCodes["DUP"] = DUP;


	m_codeFunctions[PUSH] = std::bind(firmware::push, std::ref(a_bus));
	m_codeFunctions[ADD] = std::bind(firmware::add, std::ref(a_bus));
	m_codeFunctions[SUB] = std::bind(firmware::sub, std::ref(a_bus));
	m_codeFunctions[DUP] = std::bind(firmware::dup, std::ref(a_bus));
	
}


bool Mapper::find(std::string a_instructionName)
{
	auto it = m_opCodes.find(a_instructionName);

	if(it != m_opCodes.end())
	{
		return 1;
	}

	return 0;
}

std::map<std::string, opCode> const& Mapper::opcodes_map()
{
	return m_opCodes;
}

std::map<opCode, std::function<void()>> const& Mapper::functions_map()
{
	return m_codeFunctions;
}

