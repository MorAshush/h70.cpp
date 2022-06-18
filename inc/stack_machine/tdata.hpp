#ifndef TDATA_HPP
#define TDATA_HPP

#include <string>

#include"token_base.hpp"

class Tdata: public TokenBase
{

public:
	Tdata(unsigned long a_data);

	virtual std::string const& type() const;
	unsigned long data() const;

private:
	static const std::string TYPE;
	unsigned long m_data;

};

#endif//TDATA_HPP