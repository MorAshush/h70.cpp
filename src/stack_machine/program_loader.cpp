#include <fstream>
#include <cassert>

#include "program_loader.hpp"


namespace in
{

ProgramLoader::ProgramLoader(char* a_fileName)
: m_fileName(a_fileName)
{
}

std::string ProgramLoader::load()
{
    std::string programString;

    std::ifstream fin;
    fin.open(m_fileName);
    assert(fin && "file couldn't be opened");

    std::string line;

    getline(fin, line);
    while(fin)
    {
        programString += line;
        programString += '\n';
        getline(fin, line);
    }

    fin.close();

    return programString; 
}
    
}//namespace in