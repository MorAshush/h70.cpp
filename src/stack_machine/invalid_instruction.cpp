#include "invalid_instruction.hpp"



namespace expt
{

InvalidCmdErr::InvalidCmdErr(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}

InvalidCmdErr::~InvalidCmdErr() noexcept
{

}

void InvalidCmdErr::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}

const char* InvalidCmdErr::what() const noexcept
{
	return m_what.c_str();
}


}//namespace expt