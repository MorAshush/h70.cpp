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
#include "or.hpp"
#include "xor.hpp"
#include "not.hpp"
#include "stor.hpp"
#include "jmp.hpp"
#include "jz.hpp"
#include "dup.hpp"
#include "swap.hpp"
#include "rol3.hpp"
#include "jnz.hpp"
#include "drop.hpp"
#include "compl.hpp"
#include "in.hpp"
#include "out.hpp"
#include "outnum.hpp"
#include "innum.hpp"


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