#ifndef JGI_HPP
#define JGI_HPP

#include <string>

#include "indirect_jmp.hpp"

namespace act
{

class Jgi: public IndirectJmp
{
public:
    Jgi();
    ~Jgi();

public:
    virtual bool compare_func(unsigned long a_first, unsigned long a_second);
    static const std::string NAME;
};

Instruction* create_jgi();


}//namespace act


#endif//JGI_HPP