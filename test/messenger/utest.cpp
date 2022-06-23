#include <string>
#include <cstddef>
#include <cstring>
#include <ctype.h>
#include <sstream>
#include <cstdio>
#include <list>
#include <vector>

#include "messenger.hpp"
#include "text_transformer.hpp"
#include "text_input.hpp"
#include "text_output.hpp"
#include "uppercase.hpp"
#include "lowercase.hpp"
#include "rot13.hpp"
#include "censor.hpp"
#include "file_input.hpp"
#include "keyboard.hpp"
#include "udp_socket_input.hpp"
#include "file_output.hpp"
#include "screen.hpp"
#include "udp_socket_output.hpp"
#include "multi_transformer.hpp"
#include "map_creator.hpp"
#include "transformers_factory.hpp"

std::list<std::string> string_parser(std::string a_string, char a_delimeter)
{
	std::list<std::string> namesList;
	std::string word;

	size_t stringLen = a_string.length();

	for(size_t i = 0; i < stringLen; ++i)
	{
		if(a_string[i] != a_delimeter)
		{
			word += a_string[i];
		}
		else if(a_string[i] == a_delimeter)
		{
			namesList.push_back(word);
			word = "";
		}
	}
	namesList.push_back(word);

	return namesList;
}

in::TextInput* get_inputer(std::string const& a_string)
{
	if(a_string == "stdin")
	{
		return new in::Keyboard;
	}
	else if(isalpha(a_string[0]))
	{
		char* cstr = new char[a_string.length() + 1];

		strcpy(cstr, a_string.c_str());

		return new in::FileInput(cstr);
	}

	return in::create_udpSocket_inputer(a_string);
}

text::TextTransformer* get_transformer(std::string const& a_string)
{
	if(a_string.find('+') != std::string::npos)
	{
		std::list<std::string> namesList = string_parser(a_string, '+');

		MapCreator transformersMap;

		TransformersFactory factory(transformersMap.get_map());
		std::vector<text::TextTransformer*> vec = factory.create(namesList);

		return new text::MultiTransformer(vec);
	}
	else if(a_string == "censor")
	{
		return new text::Censor;
	}
	else if(a_string == "rot13")
	{
		return new text::RotThirteen();
	}
	else if(a_string == "uppercase")
	{
		return new text::UpperCase();
	}

	return new text::LowerCase();	
}

out::TextOutput* get_outputer(std::string const& a_string)
{
	if(a_string == "stdout")
	{
		return new out::Screen;
	}
	else if(isalpha(a_string[0]))
	{
		char* cstr = new char[a_string.length() + 1];
		
		strcpy(cstr, a_string.c_str());

		return new out::FileOutput(cstr);
	}

	return out::create_udpSocket_outputer(a_string);
}


int main(int argc, char* argv[])
{

	in::TextInput* i = get_inputer(argv[1]);
	text::TextTransformer* t = get_transformer(argv[2]);
	out::TextOutput* o = get_outputer(argv[3]);


	Messenger m(*i, *t, *o);
	m.execute();

	delete i;
	delete t;
	delete o;

	return 0;
}
