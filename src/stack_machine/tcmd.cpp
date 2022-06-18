#include "tcmd.hpp"




Tcmd::Tcmd(std::string const& a_type, std::string const& a_name)
: m_type(a_type)
, m_name(a_name)
{

}

std::string const& Tcmd::type() const
{
	return m_type;
}

std::string const& Tcmd::name() const
{
	return m_name;
}