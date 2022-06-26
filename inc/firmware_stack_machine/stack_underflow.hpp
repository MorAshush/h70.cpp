#ifndef STACK_UNDERFLOW_HPP
#define STACK_UNDERFLOW_HPP


#include <iostream>
#include <string>

#include"error.hpp"

namespace expt
{

class UnderFlowErr: public Error
{
public:
	UnderFlowErr(const char* a_func, const char* a_what);
	virtual ~UnderFlowErr() noexcept;

	virtual void print(std::ostream& a_os) const;

	virtual const char* what() const noexcept;

private:
	std::string m_func;
	std::string m_what;
};

}//namespace expt


#endif// STACK_UNDERFLOW_HPP