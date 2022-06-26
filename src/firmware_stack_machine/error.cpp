#include "error.hpp"




namespace expt
{

Error::~Error() noexcept
{
}

std::ostream& operator<<(std::ostream& a_os, Error const& a_err)
{
	a_err.print(a_os);
	return a_os;
}

}//namespace expt