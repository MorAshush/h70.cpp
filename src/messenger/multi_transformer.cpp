#include <iostream>
#include <cstddef>

#include "multi_transformer.hpp"
#include "uppercase.hpp"
#include "lowercase.hpp"
#include "rot13.hpp"
#include "censor.hpp"

namespace text
{

MultiTransformer::MultiTransformer(std::string const& a_transformers)
: TextTransformer()
{
	m_transformers.reserve(10);

	extract_transformers(a_transformers);
}


std::string MultiTransformer::transform(std::string& a_string)
{
	size_t size = m_transformers.size();

	for(size_t i = 0; i < size; ++i)
	{
		m_transformers[i]->transform(a_string);
	}

	return a_string;
}

void MultiTransformer::extract_transformers(std::string const& a_string)
{
	std::string transformer;

	size_t i = 0;
	size_t len = a_string.length();

	while(i < len)
	{
		if(a_string[i] != '+')
		{
			transformer += a_string[i];
		}
		else
		{
			m_transformers.push_back(get_transformer(transformer));
			transformer = "";
		}

		++i;
	}
	m_transformers.push_back(get_transformer(transformer));
}

TextTransformer* MultiTransformer::get_transformer(std::string const& a_string)
{
	if(a_string == "censor")
	{
		return new Censor;
	}
	else if(a_string == "rot13")
	{
		return new RotThirteen();
	}
	else if(a_string == "uppercase")
	{
		return new UpperCase();
	}

	return new LowerCase();	
}

}//namespace text