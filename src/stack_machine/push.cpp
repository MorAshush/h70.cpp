#include "push.hpp"

namespace act
{

const std::string Push::NAME = "PUSH";

Push::Push(mng::Controller* a_controller)
: m_controller(a_controller)
{
}

Push::~Push()
{
}

void Push::execute()
{
	++m_controller;
}

Instruction* create_push(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Push(a_controller);
}

}//namespace act