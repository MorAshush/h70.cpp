#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>

#include "file_output.hpp"
#include "text_output.hpp"


namespace out
{

FileOutput::FileOutput(char* a_fileName)
: TextOutput()
, m_fileName(a_fileName)
{
}

void FileOutput::send(std::string const& a_text)
{
	std::ofstream fout;
	fout.open(m_fileName);

	assert(fout && "file couldn't be opened");

	fout << a_text;

	fout.close();
}




}//namespace out
