#include <list>
#include <iterator>
#include <iostream>

#include "factory.hpp"
#include "instruction_arg.hpp"



Factory::Factory(Grammar a_grammar)
: m_grammar(a_grammar)
{
}

std::vector<act::Instruction*> Factory::create(std::list<std::string> const& a_instructionsList,
												container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	std::vector<act::Instruction*> instructions;

	instructions.reserve(a_instructionsList.size());

	std::list<std::string>::const_iterator current = a_instructionsList.begin();
	std::list<std::string>::const_iterator end = a_instructionsList.end();

	while(current != end)
	{
		std::string instrutctionName = *current;
		act::Instruction* i = m_grammar.creator_func(instrutctionName)(a_stack, a_controller, a_memory);
		if(!i)
		{
			//throw invalidInstruction execption
		}
		else
		{
			instructions.push_back(i);
		}

		size_t argsNum = m_grammar.args_num(instrutctionName);
		if(argsNum)
		{
			++current;
			if(current == end)
			{
				break;
			}

			instrutctionName = *current;
			
			for(size_t j = 0; j < argsNum; ++j)
			{
				if(current == end || isalpha(instrutctionName[0]))
				{
					//throw missingArgument exception
				}

				act::Arg* i = act::create_arg(a_stack, a_controller, a_memory);
				i->set_arg(instrutctionName);
				instructions.push_back(i);
				++current;
			}
		}
		else
		{
			++current;
		}
	}

	return instructions;
}


/*while(current != end)
	{
		size_t argsNum = m_grammar.args_num(*current);

		if(!argsNum)
		{
			std::string s = *current;
			act::Instruction* i = m_grammar.creator_func(*current)(a_stack, a_controller, a_memory);
			if(!i)
			{
				//throw invalidInstruction execption
			}

			instructions.push_back(i);
			++current;
		}
		if(argsNum)
		{
			act::Instruction* i = m_grammar.creator_func(*current)(a_stack, a_controller, a_memory);
			if(!i)
			{
				//throw invalidInstruction execption
			}

			instructions.push_back(i);
			++current;
			std::string s = *current;
			
			for(size_t j = 0; j < argsNum; ++j)
			{
				if(current == end || isalpha(s[0]))
				{
					//throw missingArgument exception
				}

				act::Instruction* i = m_grammar.creator_func(*current)(a_stack, a_controller, a_memory);
//				i->set_arg(s);
				instructions.push_back(i);
				++current;
			}
		}		

		*/