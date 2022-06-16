#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>

#include "instruction_base.hpp"
#include "nop.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "and.hpp"
#include "hlt.hpp"
#include "load.hpp"
#include "instruction_arg.hpp"
#include "push.hpp"


typedef act::Instruction* (*functionPtr)(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

class Grammar
{

public:
	Grammar();

	size_t args_num(std::string const& a_instructionName);
	functionPtr creator_func(std::string const& a_instructionName);

private:
	std::map<std::string, size_t> m_argsTable;
	std::map<std::string, functionPtr> m_creatorsTable;
};


#endif //GRAMMAR_HPP