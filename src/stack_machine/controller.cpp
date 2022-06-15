#include "controller.hpp"


namespace mng
{

Controller::Controller(act::Instruction* a_ptr, size_t a_ptrIndex)
: m_ip(a_ptr, a_ptrIndex)
{
}

act::Instruction* Controller::inc_ptr()
{
	++m_ip;

	return m_ip.get_ptr();
}

act::Instruction* Controller::dec_ptr()
{
	--m_ip;

	return m_ip.get_ptr();
}

act::Instruction* Controller::jump_to(size_t a_address)
{
	m_ip.jump_to(a_address);

	return m_ip.get_ptr();
}


}//namspace mng