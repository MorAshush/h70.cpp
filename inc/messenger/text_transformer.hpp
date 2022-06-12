#ifndef TEXT_TRANSFORMER_HPP
#define TEXT_TRANSFORMER_HPP

#include <string>

namespace text
{

//abstract pure class
class TextTransformer{
public:
    virtual ~TextTransformer(); 

    virtual std::string transform(std::string& a_string) = 0;

//    virtual std::string retransform(std::string& a_string) = 0;
};




}//namespace text


#endif //TEXT_TRANSFORMER_HPP