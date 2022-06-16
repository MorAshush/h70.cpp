#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <vector>
#include <list>

#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"
#include "instruction_base.hpp"
#include "grammar.hpp"

class Factory
{

public:
	Factory(Grammar a_grammar);

	std::vector<act::Instruction*> create(std::list<std::string> const& a_instructionsList,
											container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory);

private:
	Grammar m_grammar;
};




#endif//FACTORY_HPP