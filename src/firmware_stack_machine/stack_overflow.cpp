#include "stack_overflow.hpp"



namespace expt
{

OverFlowErr::OverFlowErr(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}

OverFlowErr::~OverFlowErr() noexcept
{

}

void OverFlowErr::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}

const char* OverFlowErr::what() const noexcept
{
	return m_what.c_str();
}


}//namespace expt