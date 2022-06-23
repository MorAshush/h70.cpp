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

//  virtual ~RotThirteen();  
    RotThirteen();
    
    virtual std::string transform(std::string& a_string);

public:
    
    static std::string const& name();

private:

    static const std::string m_name;
};

TextTransformer* create_rotThirteen();


}//namespace text

#endif // ROT13_HPP