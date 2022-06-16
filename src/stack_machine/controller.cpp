#include "controller.hpp"


namespace mng
{

Controller::Controller()
: m_ip(0)
{
}

void Controller::operator++()
{
	++m_ip;
}

void Controller::operator--()
{
	--m_ip;
}

void Controller::jump_to(size_t a_address)
{
	m_ip = a_address;
}

size_t Controller::ip()
{
	return m_ip;
}


void Controller::execute_instruction(act::Instruction* a_instruction)
{
	a_instruction->execute();
}

}//namspace mng