#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <vector>
#include <cstdint>

typedef std::vector<uint8_t> Buffer;

typedef std::vector<uint8_t>(*cmdFunc)(std::vector<uint8_t>const&);











#endif//DEFINITIONS_HPP