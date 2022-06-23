#ifndef UPPERCASE_HPP
#define UPPERCASE_HPP

#include <string>
#include <locale>

#include "text_transformer.hpp"


namespace text
{

// UpperCase implements the abstraction
// UpperCase is-a TextTransformer
class UpperCase: public TextTransformer {
public:

//  virtual ~UpperCase(); 
    UpperCase();
    
    virtual std::string transform(std::string& a_string);

public:
    
    static std::string const& name();

private:

    static const std::string m_name;

private:

    std::locale m_locale; 
};


TextTransformer* create_uppercase();

}//namespace text

#endif // UPPERCASE_HPP