#ifndef INVALID_INSTRUCTION_HPP
#define INVALID_INSTRUCTION_HPP


#include <iostream>
#include <string>

#include"error.hpp"

namespace expt
{

class InvalidCmdErr: public Error
{
public:
	InvalidCmdErr(const char* a_func, const char* a_what);
	virtual ~InvalidCmdErr() noexcept;

	virtual void print(std::ostream& a_os) const;

	virtual const char* what() const noexcept;

private:
	std::string m_func;
	std::string m_what;
};

}//namespace expt


#endif// INVALID_INSTRUCTION_HPP