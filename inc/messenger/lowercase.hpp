#ifndef LOWERCASE_HPP
#define LOWERCASE_HPP

#include <string>
#include <locale>

#include "text_transformer.hpp"


namespace text
{

class LowerCase: public TextTransformer {
public:
    
//  virtual ~LowerCase();  
    LowerCase();
    
    virtual std::string transform(std::string& a_string);

public:

    static std::string const& name();

private:
    
    static const std::string m_name;

private:
    
    std::locale m_locale; 
};

TextTransformer* create_lowercase();


}//namespace text

#endif // LOWERCASE_HPP