#include <cstddef>

#include "lowercase.hpp"

namespace text
{

LowerCase::LowerCase()
: TextTransformer()
{
}

std::string LowerCase::transform(std::string& a_string)
{
	size_t len = a_string.length();

	for(size_t i = 0; i < len; ++i)
	{
		a_string[i] = std::tolower(a_string[i], m_locale);
	}

	return a_string; 
}

}//namespace text