#include <string>
#include <iostream>
#include <cstddef>
#include <list>
#include <iterator>
#include <map>

#include "censor.hpp"
#include "text_transformer.hpp"

namespace text
{

Censor::Censor(std::list<std::string>  a_badWords)
: TextTransformer()
{
	std::list<std::string>::iterator it = a_badWords.begin();
	std::list<std::string>::iterator end = a_badWords.end();

	while(it != end)
	{
		m_badWords.insert(std::pair<std::string, bool>(*it, 0));
		++it;
	}
}


std::string Censor::transform(std::string& a_string)
{
	std::string word = "";

	size_t len = a_string.length();

	for(size_t i = 0; i <= len; ++i)
	{
		if(a_string[i] != ' ' && a_string[i] != ',' && a_string[i] != '.' && a_string[i] != '!' && a_string[i] != '\0')
		{
			word += a_string[i];
		}
		else
		{
			if(m_badWords.find(word) != m_badWords.end())
			{
				size_t j = i;
				j -= word.length();
				for(size_t f = 0; f < word.length(); ++f)
				{
					a_string[j] = '*';
					++j;
				}
			}

			word = "";
		}
	}

	return a_string; 
}

}//namespace text