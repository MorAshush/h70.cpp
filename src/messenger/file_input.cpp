#include <fstream>
#include <cassert>

#include "file_input.hpp"


namespace in
{

FileInput::FileInput(const char* a_fileName)
: TextInput()
, m_fileName(a_fileName)
{
}

std::string FileInput::recieve()
{
	std::string data;

	std::ifstream fin;
	fin.open(m_fileName);
	assert(fin && "file couldn't be opened");

	std::string line;

	getline(fin, line);
	while(fin)
	{
		data += line;
		data += '\n';
		getline(fin, line);
	}

	fin.close();

	return data; 
}




}//namespace in
