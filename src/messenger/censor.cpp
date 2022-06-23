#include <iostream>
#include <cstddef>
#include <iterator>

#include "censor.hpp"

namespace text
{

Censor::Censor()
: TextTransformer()
{
	m_badWords.insert(std::pair<std::string, bool>("fat", 0));
	m_badWords.insert(std::pair<std::string, bool>("FAT", 0));
	m_badWords.insert(std::pair<std::string, bool>("ugly", 0));
	m_badWords.insert(std::pair<std::string, bool>("UGLY", 0));
	m_badWords.insert(std::pair<std::string, bool>("stupid", 0));
	m_badWords.insert(std::pair<std::string, bool>("STUPID", 0));

//	m_badWords.insert(std::pair<std::string, bool>(*it, 0));
}


std::string Censor::transform(std::string& a_string)
{
	std::string word = "";

	size_t len = a_string.length();
	size_t i = 0;
	for(i = 0; i < len - 1; ++i)
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


	return a_string; 
}

std::string const Censor::m_name = "censor";

std::string const& Censor::name()
{
	return m_name;
}


TextTransformer* create_censor()
{
    return new Censor;
}


}//namespace text