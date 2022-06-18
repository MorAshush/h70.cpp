#ifndef TOKEN_BASE_HPP
#define TOKEN_BASE_HPP

#include <string>

class TokenBase
{

public:
    virtual ~TokenBase(); 

    virtual std::string const& type() const = 0;
};



#endif// TOKEN_BASE_HPP