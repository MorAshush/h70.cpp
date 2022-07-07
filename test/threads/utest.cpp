#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>

#include "thread_safe_queue.hpp"

typedef std::vector<int64_t> IV;

std::vector<IV> generate_vec_of_vecs()
{
	std::vector<IV> vv;

	srand(time(0));
	size_t size = rand() % 85 + 15;

	vv.reserve(size);

	for(size_t i = 0; i < size; ++i)
	{
		int randCapacity = rand() % 30 + 1;
		int randInitValue = rand() % 30;

		IV newVec(randCapacity, randInitValue);
		vv.push_back(std::move(newVec));
 	}

 	return vv;
}

std::ostream& operator<<(std::ostream& a_os, std::vector<int64_t> const& a_vec)
{
	size_t size = a_vec.size();

	a_os << '[';
	for(size_t i = 0; i < size; ++i)
	{
		a_os << a_vec[i];

		if(i != size - 1)
		{
			a_os << ", ";
		}
	}

	std::cout << "]\n";

	return a_os;
}

void que_print(SafeQueue<IV> const& a_que)
{
	SafeQueue<IV> queCopy(a_que);

	size_t size = queCopy.size();

	std::list<IV> elements;

	for(size_t i = 0; i < size; ++i)
	{
		IV element;
		queCopy.dequeue(element);	
		elements.push_front(element);
	}

	auto it = elements.begin();
	auto end = elements.end();

	while(it != end)
	{
		std::cout << *it << ", ";

		++it;
	}

	std::cout << "\n\n";
}

int main()
{
	SafeQueue<IV> sq;

	IV vec;

	auto safe_pop = [&sq](IV& a_vec)
	{
		sq.dequeue(a_vec);
	};

	std::vector<IV> resource = generate_vec_of_vecs();
		std::cout << "start - the queue size is: " << sq.size() << "\n\n";
	
	std::thread producer1(&SafeQueue<IV>::enqueue, std::ref(sq), std::ref(resource[0]));
	std::thread producer2(&SafeQueue<IV>::enqueue, std::ref(sq), std::ref(resource[1]));
	std::thread producer3(&SafeQueue<IV>::enqueue, std::ref(sq), std::ref(resource[2]));
	std::thread producer4(&SafeQueue<IV>::enqueue, std::ref(sq), std::ref(resource[3]));
	std::thread producer5(&SafeQueue<IV>::enqueue, std::ref(sq), std::ref(resource[4]));

	std::thread consumer1(safe_pop, std::ref(vec));
/*	std::thread consumer2(safe_pop, std::ref(vec));
	std::thread consumer3(safe_pop, std::ref(vec));
	std::thread consumer4(safe_pop, std::ref(vec));
*/

	producer1.join();
	producer2.join();
	producer3.join();
	producer4.join();
	producer5.join();

	consumer1.join();
/*	consumer2.join();
	consumer3.join();
	consumer4.join();
*/
	std::cout << "end - the queue size is: " << sq.size() << '\n';

	que_print(sq);

	return 0;
}