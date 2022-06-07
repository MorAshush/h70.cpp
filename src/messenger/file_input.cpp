#include <string>
#include <cstddef>
#include <fstream>
#include <cstdio>
#include <iostream>

#include <iostream>
#include <cassert>
#include <string>

#include "file_input.hpp"
#include "text_input.hpp"


namespace in
{

FileInput::FileInput(char* a_fileName)
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
