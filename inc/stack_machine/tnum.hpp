#ifndef TNUM_HPP
#define TNUM_HPP

#include <string>

#include"token_base.hpp"

class Tnum: public TokenBase
{

public:
	Tnum(std::string const& a_type, std::string const& a_value);

	virtual std::string const& type() const;
	unsigned long value() const;

private:
	std::string m_type;
	unsigned long m_value;

};


#endif//TNUM_HPP