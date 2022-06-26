#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <list>
#include <vector>

#include "mapper.hpp"

class Parser
{
public:

    Parser(Mapper const& a_mapper);

    std::list<std::string> const& parse(std::string const& a_string, char a_delimeter);
    std::vector<opCode> const& compile();

private:
    Mapper m_mapper;
    std::list<std::string> m_wordsList;
    std::vector<opCode> m_code;
};






#endif//PARSER_HPP