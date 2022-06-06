#include <string>
#include <locale>
#include <cstddef>
#include <iostream>
#include <ctype.h>

#include "rot13.hpp"
#include "text_transformer.hpp"

namespace text
{

RotThirteen::RotThirteen()
: TextTransformer()
{
}

std::string RotThirteen::transform(std::string& a_string)
{
	for(size_t i = 0; i <= a_string.length(); ++i)
	{
		if(isupper(a_string[i]) && (a_string[i] + 13 <= 90))
		{
			a_string[i] = a_string[i] + 13;
		}
		else if(isupper(a_string[i]) && (a_string[i] + 13 > 90))
		{
			a_string[i] = 64 + (a_string[i] + 13) % 90;
		}
		else if(islower(a_string[i]) && (a_string[i] + 13 <= 122))
		{
			a_string[i] = a_string[i] + 13;
		}
		else if(islower(a_string[i]) && (a_string[i] + 13 > 122))
		{
			a_string[i] = 96 + (a_string[i] + 13) % 122;
		}
	}

	return a_string; 
}
/*
std::string RotThirteen::retransform(std::string& a_string)
{
	return transform(a_string); 
}
*/
}//namespace text