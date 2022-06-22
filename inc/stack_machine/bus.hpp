#ifndef BUS_HPP
#define BUS_HPP

#include <cstddef>
#include <vector>

namespace container
{
	template <typename T>
	class Stack;
}

namespace mng
{
	class Memory;
	class Controller;
}

namespace act
{
	class Instruction;
}


class Bus
{
public:
	Bus();
	~Bus();

	void set_bus(container::Stack<unsigned long>* a_numStack, container::Stack<unsigned long>* m_ptrStack,
																 mng::Memory* a_memory, mng::Controller* a_controller);

	container::Stack<unsigned long>* numbers_stack() const;
	container::Stack<unsigned long>* pointers_stack() const;
	mng::Memory* memory() const;
	mng::Controller* controller() const;

private:
	container::Stack<unsigned long>* m_numStack;
	container::Stack<unsigned long>* m_ptrStack;
	mng::Memory* m_memory;
	mng::Controller* m_controller;
};


#endif//BUS_HPP