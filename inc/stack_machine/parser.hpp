#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <list>


namespace act
{


class Parser
{
public:
    Parser();
    std::list<std::string> const& parse(std::string& a_string, char a_delimeter);

private:
    std::list<std::string> m_words;
};

}//namespace act






#endif//PARSER_HPP