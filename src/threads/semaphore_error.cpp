#include "semaphore_error.hpp"


SemaphoreError::SemaphoreError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}
/*
void SemaphoreError::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}
*/
const char* SemaphoreError::what() const noexcept
{
	return m_what.c_str();
}