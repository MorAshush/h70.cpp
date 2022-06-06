#ifndef UPPERCASE_HPP
#define UPPERCASE_HPP

#include <string>

#include "text_transformer.hpp"


namespace text
{

// UpperCase implements the abstraction
// UpperCase is-a TextTransformer
class UpperCase: public TextTransformer {
public:
    UpperCase();
    
    virtual std::string transform(std::string& a_string);

//    virtual ~UpperCase();  
};

}//namespace text

#endif // UPPERCASE_HPP