#include <iterator>
#include <sstream>
#include <map>
#include <iterator>
#include <ctype.h>

#include "parser.hpp"
#include "invalid_instruction.hpp"
#include "missing_argument.hpp"

Parser::Parser(Mapper const& a_mapper)
: m_mapper(a_mapper)
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

std::vector<int> const& Parser::compile()
{
	std::vector<opCode> code;

	auto itName = m_wordsList.begin();
	auto listEnd = m_wordsList.end();

	auto opCodesMap = m_mapper.opcodes_map();

	while(itName != listEnd)
	{
		if(m_mapper.find(*itName))
		{
			std::string name = *itName;
			code.push_back(opCodesMap[name]);

			if((*itName == "PUSH") || (*itName == "PUSHIP"))
			{
				++itName;
				name = *itName;
				if(isalpha(name))
				{
					throw expt::MissingArgErr("Parser::compile", "missing argument for instruction");
				}

				code.push_back(stoi(name));
			}
		}
		else
		{
			std::cout << *itName << '\n';
			throw expt::InvalidCmdErr("Parser::compile", "invalid command in program");
		}

		++itName;
	}

}

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