#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <vector>
#include <list>

#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "instruction_base.hpp"
#include "grammar.hpp"

class Factory
{

public:
	Factory(Grammar const& a_grammar);

	std::vector<act::Instruction*> create(std::list<std::string> const& a_instructionsList);

private:
	Grammar m_grammar;
};




#endif//FACTORY_HPP