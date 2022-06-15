#ifndef PROGRAM_LOADER_HPP
#define PROGRAM_LOADER_HPP

#include <string>


namespace in
{

class ProgramLoader 
{
public:
    ProgramLoader(char* a_fileName);
    
    std::string load();

private:
	char* m_fileName;
};




}//namespace in


#endif //PROGRAM_LOADER_HPP