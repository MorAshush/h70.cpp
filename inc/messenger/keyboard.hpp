#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <string>

#include "text_input.hpp"

namespace in
{

class Keyboard: public TextInput 
{
public:

//  virtual ~Keyboard(); 
    Keyboard();
    
    virtual std::string recieve();
};




}//namespace in





#endif//KEYBOARD.HPP