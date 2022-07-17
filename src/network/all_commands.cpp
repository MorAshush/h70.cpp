#include <string>
#include <fstream>
#include <iostream>

#include "all_commands.hpp"


std::vector<uint8_t> add(std::vector<uint8_t>const& a_buffer)
{
	std::vector<uint8_t> sum(1);
	for(auto& n : a_buffer)
	{
		sum[0] += n;
	}

	return sum;
}

std::vector<uint8_t> mul(std::vector<uint8_t>const& a_buffer)
{
	std::vector<uint8_t> sum(1);
	for(auto& n : a_buffer)
	{
		sum[0] += n;
	}

	return sum;
}

std::vector<uint8_t> get(std::vector<uint8_t>const& a_fileName)
{
	std::string fileName(a_fileName.begin(), a_fileName.end());
	std::ifstream fin;
    fin.open(fileName);
    if(!fin)
    {
    	std::cout << "file couldn't open\n";
    }

    std::string fileContentStr;
    std::string line;
    getline(fin, line);
    while(fin)
    {
    	fileContentStr += line;
        fileContentStr += '\n';
    }

    fin.close();
    std::vector<uint8_t> fileContentVec(fileContentStr.begin(), fileContentStr.end());
    return fileContentVec;
}