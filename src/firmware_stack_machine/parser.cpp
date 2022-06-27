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
	m_wordsList.push_back(word);
	return m_wordsList;
}

std::vector<int64_t> const& Parser::compile()
{
	auto itName = m_wordsList.begin();
	auto listEnd = m_wordsList.end();

	auto opCodesMap = m_mapper.opcodes_map();

	while(itName != listEnd)
	{
		if(m_mapper.find(*itName))
		{
			std::string name = *itName;
			m_code.push_back(static_cast<int64_t>(opCodesMap[name]));

			if((*itName == "PUSH") || (*itName == "PUSHIP"))
			{
				++itName;
				name = *itName;
				if(!isdigit(name[0]))
				{
					throw expt::MissingArgErr("Parser::compile", "missing argument for instruction");
				}

				m_code.push_back(static_cast<int64_t>(stoi(name, nullptr)));
			}
		}
		else
		{
			std::cout << *itName << '\n';
			throw expt::InvalidCmdErr("Parser::compile", "invalid command in program");
		}

		++itName;
	}

	return m_code;

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