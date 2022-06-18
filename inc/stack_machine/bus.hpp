#ifndef BUS_HPP
#define BUS_HPP

#include <cstddef>
#include <vector>

#include "instruction_base.hpp"
#include "stack_template.hpp"
#include "memory.hpp"
#include "controller.hpp"



class Bus
{
public:
	Bus();
	~Bus();

	void set_bus(Container::Stack<unsigned long>* a_numStack, Stack<act::Instruction*>* m_ptrStack,
																 mng::Memory* a_memory, mng::Controller* a_controller);

	Stack<unsigned long>* numbers_stack() const;
	Stack<act::Instruction*>* pointers_stack() const;
	mng::Memory* memory() const;
	mng::Controller* controller() const;

private:
	Stack<unsigned long>* m_numStack;
	Stack<act::Instruction*>* m_ptrStack;
	mng::Memory* m_memory;
	mng::Controller* m_controller;
};


#endif//BUS_HPP