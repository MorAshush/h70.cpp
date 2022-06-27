#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "bus.hpp"


namespace firmware
{

	void push(Bus& a_bus);
	void add(Bus& a_bus);
	void sub(Bus& a_bus);
	void dup(Bus& a_bus);
	void hlt();


}//namespace firmware



#endif// FUNCTIONS_HPP