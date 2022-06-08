#include <string>
#include <cstdio>

#include "messenger.hpp"


Messenger::Messenger(in::TextInput& a_inputer, text::TextTransformer& a_transformer, out::TextOutput& a_outputer)
: m_inputer(a_inputer)
, m_transformer(a_transformer)
, m_outputer(a_outputer)
{

}

void Messenger::execute()
{
	std::string msg = m_inputer.recieve();

	m_transformer.transform(msg);

	m_outputer.send(msg);
}
