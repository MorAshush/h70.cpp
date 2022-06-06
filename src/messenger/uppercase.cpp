#include <string>
#include <locale>
#include <cstddef>

#include "uppercase.hpp"
#include "text_transformer.hpp"

namespace text
{

UpperCase::UpperCase()
: TextTransformer()
{
}

std::string UpperCase::transform(std::string& a_string)
{
	std::locale loc;
	for(size_t i = 0; i < a_string.length(); ++i)
	{
		a_string[i] = std::toupper(a_string[i], loc);
	}

	return a_string; 
}

}//namespace text