#include "tdata.hpp"


const std::string Tdata::TYPE = "Tdata";

Tdata::Tdata(unsigned long a_data)
: m_data(a_data)
{

}

std::string const& Tdata::type() const
{
	return TYPE;
}

unsigned long Tdata::data() const
{
	return m_data;
}