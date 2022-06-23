#include <iterator>
#include <sstream>

#include <map>
#include <iterator>

#include "parser.hpp"
#include "invalid_instruction.hpp"
#include "missing_argument.hpp"

Parser::Parser(Grammar const& a_grammar)
: m_grammar(a_grammar)
{
}

std::list<std::string> const& Parser::parse(std::string const& a_string, char a_delimeter)
{
	std::string word;

	size_t stringLen = a_string.length();

	for(size_t i = 0; i < stringLen; ++i)
	{
		if(a_string[i] != a_delimeter && a_string[i] != '\n')
		{
			word += a_string[i];
		}
		else if(a_string[i] == a_delimeter || a_string[i] == '\n')
		{
			m_wordsList.push_back(word);
			word = "";
		}
	}

	return m_wordsList;
}
/*
std::list<std::string> const& Parser::compile()
{
	std::map<std::string, int> labelsMap;

	auto it = m_wordsList.begin();
	auto listEnd = m_wordsList.end();

	while(it != listEnd)
	{
		auto instructionsTable = m_grammar.args_num();
		auto instructionsTableEnd = instructionsTable.begin();
		
		if(*it != "main:")
		{
			if(instructionsTable.find(*it) == instructionsTableEnd) //means *it is not on instructions map.
			{

			}
		}

		++it;
	}

}
*/
/*parse backup
std::list<std::string> const& Parser::parse(std::string const& a_string, char a_delimeter)
{
	std::string word;

	size_t stringLen = a_string.length();

	for(size_t i = 0; i < stringLen; ++i)
	{
		if(a_string[i] != a_delimeter && a_string[i] != '\n')
		{
			word += a_string[i];
		}
		else if(a_string[i] == a_delimeter || a_string[i] == '\n')
		{
			m_instructionsList.push_back(word);
			word = "";
		}
	}

	return m_instructionsList;
}
*/