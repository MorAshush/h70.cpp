#include <iterator>

#include "mapper.hpp"
#include "functions.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"

Mapper::Mapper(Bus& a_bus)
{
	m_opCodes["PUSH"] = PUSH;
	m_opCodes["PUSHIP"] = PUSHIP;
	m_opCodes["ADD"] = ADD;
	m_opCodes["SUB"] = SUB;
	m_opCodes["OR"] = OR;
	m_opCodes["XOR"] = XOR;
	m_opCodes["AND"] = AND;
	m_opCodes["COMPL"] = COMPL;
	m_opCodes["DROP"] = DROP;
	m_opCodes["DROPIP"] = DROPIP;
	m_opCodes["DUP"] = DUP;
	m_opCodes["IN"] = IN;
	m_opCodes["INNUM"] = INNUM;
	m_opCodes["OUT"] = OUT;
	m_opCodes["OUTNUM"] = OUTNUM;
	m_opCodes["JE"] = JE;
	m_opCodes["JEI"] = JEI;
	m_opCodes["JG"] = JG;
	m_opCodes["JGE"] = JGE;
	m_opCodes["JGI"] = JGI;
	m_opCodes["JL"] = JL;
	m_opCodes["JLE"] = JLE;
	m_opCodes["JMP"] = JMP;
	m_opCodes["JNZ"] = JNZ;
	m_opCodes["JZ"] = JZ;
	m_opCodes["LOAD"] = LOAD;
	m_opCodes["NOP"] = NOP;
	m_opCodes["NOT"] = NOT;
	m_opCodes["POPIP"] = POPIP;
	m_opCodes["ROL3"] = ROL3;
	m_opCodes["STOR"] = STOR;
	m_opCodes["SWAP"] = SWAP;
	m_opCodes["HLT"] = HLT;

	auto binary_arith = [&a_bus](auto op)
	{
		auto first = a_bus.numbers_stack()->pop();
		auto second = a_bus.numbers_stack()->pop();
		auto result = op(first, second);
		a_bus.numbers_stack()->push(result);

		mng::Controller* controller = a_bus.controller();
		++(*controller);
	};

	m_codeFunctions[ADD] = [&a_bus, binary_arith]()
	{
		binary_arith(   [](auto first, auto second){return first + second;}   );
	};

	m_codeFunctions[SUB] = [&a_bus, binary_arith]()
	{
		binary_arith(   [](auto first, auto second){return first - second;}   );
	};

	m_codeFunctions[OR] = [&a_bus, binary_arith]()
	{
		binary_arith(   [](auto first, auto second){return first | second;}   );
	};

	m_codeFunctions[XOR] = [&a_bus, binary_arith]()
	{
		binary_arith(   [](auto first, auto second){return first ^ second;}   );
	};

	m_codeFunctions[AND] = [&a_bus, binary_arith]()
	{
		binary_arith(   [](auto first, auto second){return first & second;}   );
	};

	m_codeFunctions[DUP] = std::bind(firmware::dup, std::ref(a_bus));

	m_codeFunctions[HLT] = [](){exit(0);};

	m_codeFunctions[PUSH] = [&a_bus]()
	{
		container::Stack* stack = a_bus.numbers_stack();	    
	    mng::Controller* controller = a_bus.controller();
	    mng::Memory* memory = a_bus.memory();

	    size_t currentIp = controller->ip();
	    
	    int64_t arg = memory->operator[](++currentIp);
	    stack->push(arg);

	    ++(*controller);
	    ++(*controller);
	};
}


bool Mapper::find(std::string a_instructionName)
{
	auto it = m_opCodes.find(a_instructionName);

	if(it != m_opCodes.end())
	{
		return 1;
	}

	return 0;
}

std::map<std::string, opCode> const& Mapper::opcodes_map()
{
	return m_opCodes;
}

std::map<opCode, std::function<void()>> const& Mapper::functions_map()
{
	return m_codeFunctions;
}

