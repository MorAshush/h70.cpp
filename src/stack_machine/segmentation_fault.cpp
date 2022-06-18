#include "segmentation_fault.hpp"



namespace expt
{

SegmentationFaultErr::SegmentationFaultErr(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{

}

SegmentationFaultErr::~SegmentationFaultErr() throw()
{

}

void SegmentationFaultErr::print(std::ostream& a_os) const
{
	a_os << m_func << " : " << m_what << '\n';
}

const char* SegmentationFaultErr::what() const throw()
{
	return m_what.c_str();
}


}//namespace expt