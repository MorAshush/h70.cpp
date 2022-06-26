#include "missing_argument.hpp"



namespace expt
{

MissingArgErr::MissingArgErr(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}

MissingArgErr::~MissingArgErr() noexcept
{

}

void MissingArgErr::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}

const char* MissingArgErr::what() const noexcept
{
	return m_what.c_str();
}


}//namespace expt