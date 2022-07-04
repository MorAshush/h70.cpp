#include <string>
#include <stdlib.h>

#include "address_class.hpp"

namespace net
{

	Address::Address(const char* a_address, const char* a_port)
	: m_ip(a_address)
	, m_port(atoi(a_port))
	{

	}

	const char* Address::get_ip() const
	{
		return m_ip;
	}

	int Address::get_port() const
	{
		return m_port;
	}

}