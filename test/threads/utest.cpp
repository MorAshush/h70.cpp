#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>

#include "thread_safe_queue.hpp"

class FunctionObject
{
public:

	FunctionObject()
	{

	}

	void print_message(std::string a_string)
	{
		write(a_string);
	}

	void write(std::string a_string)
	{
		std::cout << a_string << '\n';
	}
};

int main()
{
	typedef std::vector<int64_t> T;

	SafeQueue<std::vector<int64_t>> q;

	std::vector<int64_t> vec(10, 2);

	std::thread producer1(&SafeQueue<T>::push, std::ref(q), std::ref(vec));

	FunctionObject fo;
	std::thread check(&FunctionObject::print_message, std::ref(fo), "blah blah");


/*	std::thread producer2();
	std::thread producer3();
	std::thread producer4();
	std::thread producer5();

	std::thread consumer1();
	std::thread consumer2();
	std::thread consumer3();
	std::thread consumer4();
	std::thread consumer5();
*/


	return 0;
}