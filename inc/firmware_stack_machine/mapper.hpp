#ifndef MAPPER_HPP
#define MAPPER_HPP

#include <map>
#include <functional>

#include "bus.hpp"

using codeFunc = std::function<void()>;

enum class opCode
{
	PUSH,
	ADD,
	SUB,
	DUP
};

class Mapper
{

public:
	Mapper(Bus const& a_bus);

	bool find(std::string a_instructionName);
	std::map<std::string, opCode> const& opcodes_map();
	std::map<opCode, codeFunc> const& functions_map();

private:
	std::map<std::string, opCode> m_opCodes;
	std::map<opCode, codeFunc> m_codeFunctions;
};


#endif //MAPPER_HPP