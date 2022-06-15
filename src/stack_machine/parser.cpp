#include "parser.hpp"

namespace act
{

Parser::Parser()
{

}

std::list<std::string> const& Parser::parse(std::string& a_string, char a_delimeter)
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
			m_words.push_back(word);
			word = "";
		}
	}
    
	m_words.push_back(word);

	return m_words;
}


}//namespace act