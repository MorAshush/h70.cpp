#ifndef ADDRESS_CLASS_HPP
#define ADDRESS_CLASS_HPP


namespace net
{

class Address
{
public:
	Address(const char* a_address, const char* a_port);
	const char* get_ip() const;
	int get_port() const;

private:
	const char* m_ip;
	int m_port;

};

}//namespace net












#endif // ADDRESS_CLASS_HPP