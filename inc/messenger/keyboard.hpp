#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "text_input.hpp"

namespace in
{

class Keyboard: public TextInput 
{
public:
    Keyboard();
    
    virtual std::string recieve();

//    virtual ~Keyboard(); 

};




}//namespace in





#endif//KEYBOARD.HPP