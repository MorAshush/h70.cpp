#ifndef JEI_HPP
#define JEI_HPP

#include <string>

#include "indirect_jmp.hpp"

namespace act
{

class Jei: public IndirectJmp
{
public:
    Jei();
    ~Jei();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jei();


}//namespace act


#endif//JEI_HPP