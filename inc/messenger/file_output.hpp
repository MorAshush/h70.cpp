#ifndef FILE_OUTPUT_HPP
#define FILE_OUTPUT_HPP

#include "text_output.hpp"

namespace out
{

class FileOutput: public TextOutput 
{
public:
    FileOutput(char* a_fileName);
    
   virtual void send(std::string const& a_text);

//    virtual ~FileOutput(); 

private:
	char* m_fileName;
};

}//namespace out









#endif //FILE_OUTPUT_HPP