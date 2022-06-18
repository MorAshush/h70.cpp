#ifndef MISSING_ARGUMENT_HPP
#define MISSING_ARGUMENT_HPP


#include <iostream>
#include <string>

#include"error.hpp"

namespace expt
{

class MissingArgErr: public Error
{
public:
	MissingArgErr(const char* a_func, const char* a_what);
	virtual ~MissingArgErr() noexcept;

	virtual void print(std::ostream& a_os) const;

	virtual const char* what() const noexcept;

private:
	std::string m_func;
	std::string m_what;
};

}//namespace expt


#endif// MISSING_ARGUMENT_HPP