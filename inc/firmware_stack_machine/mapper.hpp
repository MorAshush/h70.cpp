#ifndef MAPPER_HPP
#define MAPPER_HPP

#include <map>
#include <functional>

#include "bus.hpp"

enum opCode : int64_t
{
	PUSH,
	PUSHIP,
	ADD,
	SUB,
	OR,
	XOR,
	AND,
	COMPL,
	DROP,
	DROPIP,
	DUP,
	IN,
	INNUM,
	OUT,
	OUTNUM,
	JE,
	JEI,
	JG,
	JGE,
	JGI,
	JL,
	JLE,
	JMP,
	JNZ,
	JZ,
	LOAD,
	NOP,
	NOT,
	POPIP,
	ROL3,
	STOR,
	SWAP,
	HLT
};

class Mapper
{

public:
	Mapper(Bus& a_bus);

	bool find(std::string a_instructionName);

	std::map<std::string, opCode> const& opcodes_map();
	std::map<opCode, std::function<void()>> const& functions_map();

private:
	std::map<std::string, opCode> m_opCodes;
	std::map<opCode, std::function<void()>> m_codeFunctions;
};


#endif //MAPPER_HPP