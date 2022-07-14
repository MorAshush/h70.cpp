#ifndef SEMAPHORE_ERROR_HPP
#define SEMAPHORE_ERROR_HPP

#include <iostream>
#include <string>
#include <exception>

class SemaphoreError: public std::exception
{

public:

	SemaphoreError(const char* a_func, const char* a_what);

//	void print(std::ostream& a_os) const;

	const char* what() const noexcept;

private:
	std::string m_func;
	std::string m_what;
};

//std::ostream& operator<<(std::ostream& a_os, Error const& a_err);


#endif //SEMAPHORE_ERROR_HPP