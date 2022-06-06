#ifndef TEXT_OUTPUT_HPP
#define TEXT_OUTPUT_HPP

#include <string>

namespace out
{

//abstract pure class
class TextOutput{
public:

    virtual void send(std::string const& a_text) = 0;
//  virtual ~TextOutput() = 0;  
};

}//namespace out











#endif//TEXT_OUTPUT_HPP