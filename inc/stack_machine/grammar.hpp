#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>

#include "instruction_base.hpp"


typedef act::Instruction* (*functionPtr)();

class Grammar
{

public:
	Grammar();

	size_t args_num(std::string const& a_instructionName);
	functionPtr creator_func(std::string const& a_instructionName);
	bool find(std::string a_instructionName);

private:
	std::map<std::string, size_t> m_argsTable;
	std::map<std::string, functionPtr> m_creatorsTable;
};


#endif //GRAMMAR_HPP