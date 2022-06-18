#include <cstring>

#include "tnum.hpp"


Tnum::Tnum(std::string const& a_type, std::string const& a_value)
: m_type(a_type)
, m_value()
{
	char* cstring = new char[a_value.length() + 1];
	strcpy(cstring, a_value.c_str());

	m_value = strtoul(cstring, NULL, 0);
	delete[] cstring;
}

std::string const& Tnum::type() const
{
	return m_type;
}

unsigned long Tnum::value() const
{
	return m_value;
}