#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>

#include "text_output.hpp"

namespace out
{

class Screen: public TextOutput 
{
public:
    Screen();
    
    virtual void send(std::string const& a_text);

//    virtual ~Screen(); 

};

}//namespace out









#endif //SCREEN_HPP