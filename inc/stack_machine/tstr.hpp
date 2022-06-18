#ifndef TSTR_HPP
#define TSTR_HPP

#include <string>

#include"token_base.hpp"

class Tstr: public TokenBase
{

public:
	Tstr(std::string const& a_type, std::string const& a_name);

	virtual std::string const& type() const;
	std::string const& name() const;

private:
	std::string m_type;
	std::string m_name;

};


#endif//TSTR_HPP