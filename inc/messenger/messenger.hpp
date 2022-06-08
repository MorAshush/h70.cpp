#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include "text_transformer.hpp"
#include "text_input.hpp"
#include "text_output.hpp"


class Messenger
{
public:

	Messenger(in::TextInput& a_inputer, text::TextTransformer& a_transformer, out::TextOutput& a_outputer);

	void execute();
//	void recieve_text();
//	void encrypt_text(std::string& a_string);
//	void send_text();

private:

	in::TextInput& m_inputer;
	text::TextTransformer& m_transformer;
	out::TextOutput& m_outputer;
};









#endif//MESSENGER_HPP
