#include <string>
#include <cstddef>
#include <fstream>
#include <cstdio>
#include <iostream>

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
	std::string line;

	while(fin)
	{
		getline(fin, line);
		std::cin >> data;
	}

	fin.close();

	return data; 
}




}//namespace in
