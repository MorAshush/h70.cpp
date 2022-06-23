#include <string>

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
#include "file_output.hpp"
#include "screen.hpp"

TextInput* get_inputer(std::string const& a_string)
{
	if(a_string == "stdin")
	{
		TextInput* i = new Keyboard;
	}
	else if(is_alpha(a_string[0]))
	{
		TextInput* i = new FileInput(a_string);
	}

//	TextOutput* i = new UDPsocketInput();

	return i;	
}

TextTransformer* get_transformer(std::string const& a_string)
{
	if(a_string == "censor")
	{
		TextInput* t = new Censor;
	}
	else if(a_string == "rot13")
	{
		TextInput* t = new RotThirteen();
	}
	else if(a_string == "uppercase")
	{
		TextInput* t = new UpperCase();
	}

	TextInput* t = new LowerCase();	

	return t;
}

TextOutput* get_outputer(std::string const& a_string)
{
	if(a_string == "stdout")
	{
		TextInput* o = new Screen;
	}
	else if(is_alpha(a_string[0]))
	{
		TextInput* o = new FileOutput(a_string);
	}

//	TextOutput* o = new UDPsocketInput();

	return o;
}


int main(int argc, char* argv[])
{

	TextInput* i = get_input(argv[1]);
	TextTransformer* t = get_transformer(argv[2]);
	TextOutput* o = get_outputer(argv[3]);

}