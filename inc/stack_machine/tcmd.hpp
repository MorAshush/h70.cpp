#ifndef TCMD_HPP
#define TCMD_HPP

#include <string>

#include"token_base.hpp"

class Tcmd: public TokenBase
{

public:
	Tcmd(std::string const& a_type, std::string const& a_value);

	virtual std::string const& type() const;
	std::string const& name() const;

private:
	std::string m_type;
	std::string m_name;

};

#endif // TCMD_HPP