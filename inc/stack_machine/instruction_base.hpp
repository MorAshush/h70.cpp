#ifndef INSTRUCTION_BASE_HPP
#define INSTRUCTION_BASE_HPP


namespace act
{

//abstract pure class
class Instruction{
public:

    virtual ~Instruction(); 

    virtual short op_code() = 0;
    virtual int execute() = 0;
};

}//namespace act















#endif //INSTRUCTION_BASE_HPP