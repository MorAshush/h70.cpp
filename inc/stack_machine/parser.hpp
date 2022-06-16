#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <list>

#include "grammar.hpp"

class Parser
{
public:

    Parser(Grammar a_grammar);

    std::list<std::string> const& parse(std::string const& a_string, char a_delimeter);

private:
    std::list<std::string> m_instructionsList;
};






#endif//PARSER_HPP