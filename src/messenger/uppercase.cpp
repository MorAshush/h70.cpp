#include <cstddef>

#include "uppercase.hpp"

namespace text
{

UpperCase::UpperCase()
: TextTransformer()
{
}

std::string UpperCase::transform(std::string& a_string)
{
	size_t len = a_string.length();

	for(size_t i = 0; i < len; ++i)
	{
		a_string[i] = std::toupper(a_string[i], m_locale);
	}

	return a_string; 
}

std::string const UpperCase::m_name = "uppercase";

std::string const& UpperCase::name()
{
	return m_name;
}

TextTransformer* create_uppercase()
{
	return new UpperCase;
}



}//namespace text