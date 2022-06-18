#include <cstring>

#include "stack_underflow.hpp"



namespace expt
{

UnderFlowErr::UnderFlowErr(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}

UnderFlowErr::~UnderFlowErr() noexcept
{

}

void UnderFlowErr::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}

const char* UnderFlowErr::what() const noexcept
{
	return m_what.c_str();
}


}//namespace expt