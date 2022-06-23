#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <list>

#include "grammar.hpp"

class Parser
{
public:

    Parser(Grammar const& a_grammar);

    std::list<std::string> const& parse(std::string const& a_string, char a_delimeter);
    std::list<std::string> const& compile();

private:
    Grammar m_grammar;
    std::list<std::string> m_wordsList;
};






#endif//PARSER_HPP