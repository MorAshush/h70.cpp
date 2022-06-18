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
	m_argsTable[act::Or::NAME] = 0;
	m_argsTable[act::Xor::NAME] = 0;
	m_argsTable[act::Not::NAME] = 0;
	m_argsTable[act::Stor::NAME] = 0;
	m_argsTable[act::Jmp::NAME] = 0;
	m_argsTable[act::Jz::NAME] = 0;
	m_argsTable[act::Dup::NAME] = 0;
	m_argsTable[act::Swap::NAME] = 0;
	m_argsTable[act::RolThree::NAME] = 0;
	m_argsTable[act::Jnz::NAME] = 0;
	m_argsTable[act::Drop::NAME] = 0;
	m_argsTable[act::Compl::NAME] = 0;
	m_argsTable[act::In::NAME] = 0;
	m_argsTable[act::Out::NAME] = 0;
	m_argsTable[act::OutNum::NAME] = 0;
	m_argsTable[act::InNum::NAME] = 0;


	m_creatorsTable[act::Nop::NAME] = &act::create_nop;
	m_creatorsTable[act::Add::NAME] = &act::create_add;
	m_creatorsTable[act::Sub::NAME] = &act::create_sub;
	m_creatorsTable[act::And::NAME] = &act::create_and;
	m_creatorsTable[act::Hlt::NAME] = &act::create_hlt;
	m_creatorsTable[act::Load::NAME] = &act::create_load;
//	m_creatorsTable[act::Arg::NAME] = &act::create_arg;
	m_creatorsTable[act::Push::NAME] = &act::create_push;
	m_creatorsTable[act::Or::NAME] = &act::create_or;
	m_creatorsTable[act::Xor::NAME] = &act::create_xor;
	m_creatorsTable[act::Not::NAME] = &act::create_not;
	m_creatorsTable[act::Stor::NAME] = &act::create_stor;
	m_creatorsTable[act::Jmp::NAME] = &act::create_jmp;
	m_creatorsTable[act::Jz::NAME] = &act::create_jz;
	m_creatorsTable[act::Dup::NAME] = &act::create_dup;
	m_creatorsTable[act::Swap::NAME] = &act::create_swap;
	m_creatorsTable[act::RolThree::NAME] = &act::create_rolThree;
	m_creatorsTable[act::Jnz::NAME] = &act::create_jnz;
	m_creatorsTable[act::Drop::NAME] = &act::create_drop;
	m_creatorsTable[act::Compl::NAME] = &act::create_compl;
	m_creatorsTable[act::In::NAME] = &act::create_in;
	m_creatorsTable[act::Out::NAME] = &act::create_out;
	m_creatorsTable[act::OutNum::NAME] = &act::create_outnum;
	m_creatorsTable[act::InNum::NAME] = &act::create_innum;
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

bool Grammar::find(std::string a_instructionName)
{
	std::map<std::string, functionPtr>::iterator it = m_creatorsTable.find(a_instructionName);

	if(it != m_creatorsTable.end())
	{
		return 1;
	}

	return 0;
}

