#include "tstr.hpp"




Tstr::Tstr(std::string const& a_type, std::string const& a_name)
: m_type(a_type)
, m_name(a_name)
{

}

std::string const& Tstr::type() const
{
	return m_type;
}

std::string const& Tstr::name() const
{
	return m_name;
}