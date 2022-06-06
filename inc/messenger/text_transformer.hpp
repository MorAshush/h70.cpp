#ifndef TEXT_TRANSFORMER_HPP
#define TEXT_TRANSFORMER_HPP

#include <string>

namespace text
{

//abstract pure class
class TextTransformer{
public:
    // pure (no impl) virtual function == we got a pointer
    virtual std::string transform(std::string& a_string) = 0;
//    virtual std::string retransform(std::string& a_string) = 0;
//  virtual ~TextTransformer() = 0;  
};




}//namespace text


#endif //TEXT_TRANSFORMER_HPP