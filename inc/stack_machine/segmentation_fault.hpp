#ifndef SEGMENTATION_FAULT_HPP
#define SEGMENTATION_FAULT_HPP


#include <iostream>
#include <string>

#include"error.hpp"

namespace expt
{

class SegmentationFaultErr: public Error
{
public:
	SegmentationFaultErr(const char* a_func, const char* a_what);
	virtual ~SegmentationFaultErr() throw();

	virtual void print(std::ostream& a_os) const;

	virtual const char* what() const throw();

private:
	std::string m_func;
	std::string m_what;
};

}//namespace expt


#endif// SEGMENTATION_FAULT_HPP