#include <iterator>
#include <sstream>

#include "parser.hpp"


Parser::Parser(Grammar a_grammar)
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
			m_instructionsList.push_back(word);
			word = "";
		}
	}
	m_instructionsList.push_back(word);

	return m_instructionsList;
}
/*
std::list<std::string> const& Parser::parse(std::string const& a_string, char a_delimeter)
{
	std::stringstream ss(a_string);
	std::string line;
	std::string word;

	while(std::getline(ss, line))
	{
		if(line[0] != '#')
		{
			std::string::iterator it = line.begin();
			std::string::iterator end = line.end();
			while(it != end)
			{
				if(isalpha(*it) || )
			}
		}
	}

	return m_instructionsList;
}
*/
/*
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
			if(m_grammar.creator_func(word)) //if returned funcPtr != NULL
			{
				m_words.push_back(word);
			}
			else //if NULL
			{
				m_words.push_back("NOP");
			}
			
			word = "";
		}
	}

//last word
	if(m_grammar.creator_func(word)) //if returned funcPtr != NULL
	{
		m_words.push_back(word);
	}
	else //if NULL
	{
		m_words.push_back("NOP");
	}
    
	return m_words;
	*/

