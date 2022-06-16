#include <iterator>

#include "grammar.hpp"


Grammar::Grammar()
{
	m_argsTable[act::Nop::NAME] = 0;
	m_argsTable[act::Add::NAME] = 0;
	m_argsTable[act::Sub::NAME] = 0;
	m_argsTable[act::And::NAME] = 0;
	m_argsTable[act::Hlt::NAME] = 0;
	m_argsTable[act::Load::NAME] = 0;
	m_argsTable[act::Arg::NAME] = 0;
	m_argsTable[act::Push::NAME] = 1;


	m_creatorsTable[act::Nop::NAME] = &act::create_nop;
	m_creatorsTable[act::Add::NAME] = &act::create_add;
	m_creatorsTable[act::Sub::NAME] = &act::create_sub;
	m_creatorsTable[act::And::NAME] = &act::create_and;
	m_creatorsTable[act::Hlt::NAME] = &act::create_hlt;
	m_creatorsTable[act::Load::NAME] = &act::create_load;
//	m_creatorsTable[act::Arg::NAME] = &act::create_arg;
	m_creatorsTable[act::Push::NAME] = &act::create_push;
}

size_t Grammar::args_num(std::string const& a_instructionName)
{
	std::map<std::string, size_t>::iterator it = m_argsTable.find(a_instructionName);

	if(it != m_argsTable.end())
	{
		return it->second;
	}

	return -1;
}

functionPtr Grammar::creator_func(std::string const& a_instructionName)
{
	std::map<std::string, functionPtr>::iterator it = m_creatorsTable.find(a_instructionName);

	if(it != m_creatorsTable.end())
	{
		return it->second;
	}

	return 0;

//	it = m_creatorsTable.find("NOP");
//	return it->second;
}
