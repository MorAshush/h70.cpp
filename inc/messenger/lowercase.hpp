#ifndef LOWERCASE_HPP
#define LOWERCASE_HPP

#include <string>

#include "text_transformer.hpp"


namespace text
{

class LowerCase: public TextTransformer {
public:
    LowerCase();
    
    virtual std::string transform(std::string& a_string);

//    virtual ~LowerCase();  
};

}//namespace text

#endif // LOWERCASE_HPP