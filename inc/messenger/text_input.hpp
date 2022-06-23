#ifndef TEXT_INPUT_HPP
#define TEXT_INPUT_HPP

#include <string>

namespace in
{

//abstract pure class
class TextInput{
public:

    virtual ~TextInput();   

    virtual std::string recieve() = 0;
};

}//namespace input















#endif //TEXT_INPUT_HPP