#ifndef ROT13_HPP
#define ROT13_HPP

#include <string>

#include "text_transformer.hpp"


namespace text
{

// RotThirteen implements the abstraction
// RotThirteen is-a TextTransformer
class RotThirteen: public TextTransformer {
public:
    RotThirteen();
    
    virtual std::string transform(std::string& a_string);
//    virtual std::string retransform(std::string& a_string);

//    virtual ~RotThirteen();  
};

}//namespace text

#endif // ROT13_HPP