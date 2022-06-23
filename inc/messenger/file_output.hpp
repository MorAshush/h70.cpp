#ifndef FILE_OUTPUT_HPP
#define FILE_OUTPUT_HPP

#include <string>

#include "text_output.hpp"

namespace out
{

class FileOutput: public TextOutput 
{
public:

//  virtual ~FileOutput(); 
    FileOutput(const char* a_fileName);
    
   virtual void send(std::string const& a_text);

private:
    
	const char* m_fileName;
};

}//namespace out









#endif //FILE_OUTPUT_HPP