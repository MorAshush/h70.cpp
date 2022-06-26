#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <string>
#include <exception>

namespace expt
{

class Error: public std::exception
{

public:
	virtual ~Error() noexcept = 0;

	virtual void print(std::ostream& a_os) const = 0;

	virtual const char* what() const noexcept = 0;
};

std::ostream& operator<<(std::ostream& a_os, Error const& a_err);


}//namespace expt

#endif //ERROR_HPP