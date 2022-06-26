#ifndef STACK_OVERFLOW_HPP
#define STACK_OVERFLOW_HPP


#include <iostream>
#include <string>

#include"error.hpp"

namespace expt
{

class OverFlowErr: public Error
{
public:
	OverFlowErr(const char* a_func, const char* a_what);
	virtual ~OverFlowErr() noexcept;

	virtual void print(std::ostream& a_os) const;

	virtual const char* what() const noexcept;

private:
	std::string m_func;
	std::string m_what;
};

}//namespace expt


#endif// STACK_OVERFLOW_HPP