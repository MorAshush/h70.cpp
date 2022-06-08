#include <string>
#include <cstddef>
#include <cstring>
#include <ctype.h>
#include <sstream>
#include <cstdio>

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



in::TextInput* get_inputer(std::string a_string)
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

	std::string ipString;
	std::string portString;
	size_t i = a_string.find(':', 0);
	ipString = a_string.substr(0, i);
	portString = a_string.substr(i + 1);

	char* ip = new char[ipString.length() + 1];
	strcpy(ip, ipString.c_str());

	char* port = new char[portString.length() + 1];
	strcpy(port, portString.c_str());

	return new in::InputUDPsocket(ip, port);

}

text::TextTransformer* get_transformer(std::string const& a_string)
{
	if(a_string.find('+') != std::string::npos)
	{
		return new text::MultiTransformer(a_string);
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
	else
	{
		std::string ipString;
		std::string portString;
		size_t i = a_string.find(':', 0);
		ipString = a_string.substr(0, i);
		portString = a_string.substr(i + 1);

		char* ip = new char[ipString.length() + 1];
		strcpy(ip, ipString.c_str());
		
		char* port = new char[portString.length() + 1];
		strcpy(port, portString.c_str());
		
		return new out::OutputUDPsocket(ip, port);
	}
}


int main(int argc, char* argv[])
{

	in::TextInput* i = get_inputer(argv[1]);
	text::TextTransformer* t = get_transformer(argv[2]);
	out::TextOutput* o = get_outputer(argv[3]);


	Messenger m(*i, *t, *o);
	m.execute();

	return 0;
}



/*#include <list>

#include "mu_test.h"

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
#include "messenger.hpp"


void transform_text(text::TextTransformer* pf, std::string& a_string)
{
	std::cout << pf->transform(a_string);
}

BEGIN_TEST(uppercase_test)	

	std::string s("flower");
	text::UpperCase u;

	transform_text(&u, s);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(lowercase_test)	

	std::string s("FLOweR");
	text::LowerCase l;

	transform_text(&l, s);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(rot13_test_1)	

	std::string s("flower");
	text::RotThirteen r;

	transform_text(&r, s);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(rot13_test_2)	

	std::string s("sybjre");
	text::RotThirteen r;

	transform_text(&r, s);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(censoring_test)	

	std::string s("Hello, fat you are fat");
	text::Censor c;

	transform_text(&c, s);

	ASSERT_PASS();

END_TEST


void recieve_text(in::TextInput* pf)
{
	std::cout << pf->recieve();
}

BEGIN_TEST(file_input_test)

	char fileName[] = "read_file.txt";
	in::FileInput f(fileName);

	recieve_text(&f);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(keyboard_input_test)

	in::Keyboard k;

	recieve_text(&k);

	ASSERT_PASS();

END_TEST

void send_text(out::TextOutput* pf, std::string const& a_text)
{
	pf->send(a_text);
}

BEGIN_TEST(file_output_test)

	char file[] = "text_file.txt";
	out::FileOutput fo(file);
	std::string text("this is me writing to a file");

	send_text(&fo, text);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(screen_output_test)

	std::string text("this is me writing to the screen");
	out::Screen s;

	send_text(&s, text);

	ASSERT_PASS();

END_TEST


BEGIN_SUITE(tests)

	TEST(uppercase_test)

	TEST(lowercase_test)

	TEST(rot13_test_1)
	TEST(rot13_test_2)

	TEST(censoring_test)

	TEST(file_input_test)

	TEST(keyboard_input_test)

	TEST(file_output_test)

	TEST(screen_output_test)

	
	
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()

END_SUITE
*/