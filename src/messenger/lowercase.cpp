#include <string>
#include <locale>
#include <cstddef>

#include "lowercase.hpp"
#include "text_transformer.hpp"

namespace text
{

LowerCase::LowerCase()
: TextTransformer()
{
}

std::string LowerCase::transform(std::string& a_string)
{
	std::locale loc;
	for(size_t i = 0; i < a_string.length(); ++i)
	{
		a_string[i] = std::tolower(a_string[i], loc);
	}

	return a_string; 
}

}//namespace text