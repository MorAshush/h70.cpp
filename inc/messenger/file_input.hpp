#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include <string>

#include "text_input.hpp"

namespace in
{

class FileInput: public TextInput 
{
public:

//  virtual ~FileInput(); compiler will do
    FileInput(const char* a_fileName);
    
    virtual std::string recieve();

private:

	const char* m_fileName;
};




}//namespace in
















#endif//FILE_INPUT_HPP