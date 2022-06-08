#ifndef LOWERCASE_HPP
#define LOWERCASE_HPP

#include <string>
#include <locale>

#include "text_transformer.hpp"


namespace text
{

class LowerCase: public TextTransformer {
public:
    LowerCase();
    
    virtual std::string transform(std::string& a_string);

//    virtual ~LowerCase();  
private:
    std::locale m_locale; 
};

}//namespace text

#endif // LOWERCASE_HPP