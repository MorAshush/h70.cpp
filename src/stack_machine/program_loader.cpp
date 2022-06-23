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
        if(line[0] != '#' && line[0] != '\n') //exclude comments and empty new lines
        {            
            if(line[0] == '\t' || line[0] == ' ')
            {
                auto it = line.begin();
                auto end = line.end();

                while(it != end && !isalpha(*it))
                {
                    if(*it == '\t' || *it == ' ')
                    {
                        line.erase(it);
                    }
                    else
                    {
                         ++it;
                    }
                }
                programString += line;
                programString += '\n';
            } 
        }
        getline(fin, line);
    }

    fin.close();

    return programString; 
}
    
}//namespace in