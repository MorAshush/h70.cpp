#include <list>

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

	std::list<std::string> badWords;
	badWords.push_back("fat");
	badWords.push_back("ugly");
	badWords.push_back("stupid");
	badWords.push_back("retard");

	std::string s("Hello, fat you are fat");
	text::Censor c(badWords);

//	std::cout << "got this far\n";
	transform_text(&c, s);

	ASSERT_PASS();

END_TEST


void recieve_text(in::TextInput* pf)
{
	std::cout << pf->recieve();
}

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
/*
BEGIN_TEST(screen_output_test)

	std::string text("this is me writing to a file");
	out::Screen s;

	send_text(&s, text);

	ASSERT_PASS();

END_TEST
*/

BEGIN_SUITE(tests)

	TEST(uppercase_test)

	TEST(lowercase_test)

	TEST(rot13_test_1)
	TEST(rot13_test_2)

	TEST(censoring_test)

	TEST(keyboard_input_test)

	TEST(file_output_test)

/*	
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
	TEST()
	TEST()
*/
END_SUITE