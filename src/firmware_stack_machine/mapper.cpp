#include <iterator>

#include "mapper.hpp"
#include "functions.hpp"

Mapper::Mapper(Bus const& a_bus)
{
/*	container::Stack* s = a_bus.numbers_stack();
	mng::Controller* c = a_bus.controller();
	mng::Memory* m = a_bus.memory();
*/
	m_opCodes["PUSH"] = opCode::PUSH;
	m_opCodes["ADD"] = opCode::ADD;
	m_opCodes["SUB"] = opCode::SUB;
	m_opCodes["DUP"] = opCode::DUP;

/*
//	m_codeFunctions[opCode::PUSH] = std::bind(firmware::push, std::ref(s), std::ref(m), std::ref(c));
	m_codeFunctions[opCode::ADD] = std::bind(firmware::add, std::ref(s));
	m_codeFunctions[opCode::SUB] = std::bind(firmware::sub, std::ref(s));
	m_codeFunctions[opCode::DUP] = std::bind(firmware::dup, std::ref(s));
*/	
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

std::map<opCode, codeFunc> const& Mapper::functions_map()
{
	return m_codeFunctions;
}

