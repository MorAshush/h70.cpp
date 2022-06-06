#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include "text_input.hpp"

namespace in
{

class FileInput: public TextInput 
{
public:
    FileInput(char* a_fileName);
    
    virtual std::string recieve();

//    virtual ~FileInput(); 

private:
	char* m_fileName;
};




}//namespace in
















#endif//FILE_INPUT_HPP