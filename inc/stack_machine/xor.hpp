#ifndef XOR_HPP
#define XOR_HPP

#include <string>

#include "bi_instruction.hpp"

namespace act
{

class Xor: public BiInstruction
{
public:
    Xor();
    ~Xor();

public:
    virtual unsigned long actual_operation(unsigned long a_first, unsigned long a_second);    
    static const std::string NAME;
};

Instruction* create_xor();

}//namespace act


#endif//XOR_HPP