#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>

#include "thread_safe_queue.hpp"

typedef std::vector<int64_t> IV;

std::vector<IV> generate_vec_of_vecs(size_t a_size)
{
	std::vector<IV> vv;

	srand(time(0));

	vv.reserve(a_size);

	for(size_t i = 0; i < a_size; ++i)
	{
		int randCapacity = rand() % 1 + 1000000;
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
		queCopy.try_dequeue(element);	
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

void enque_work(SafeQueue<IV>& a_sq, size_t a_numOfTimes)
{
	while(a_numOfTimes-- > 0)
	{
		IV t(1000, 1);
		a_sq.enqueue(std::move(t));
	}
}

void deque_work(SafeQueue<IV>& a_sq, size_t a_numOfTimes)
{
	while(a_numOfTimes-- > 0)
	{
		IV t;
		a_sq.dequeue(t);
	}
}

void add_producers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_producersNum, size_t a_numOfInserts)
{
	while(a_producersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(enque_work, std::ref(a_sq), a_numOfInserts));
	}
}

void add_consumers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_consumersNum, size_t a_numOfPops)
{
	while(a_consumersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(deque_work, std::ref(a_sq), a_numOfPops));
	}
}

/*
void add_producers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, std::vector<IV>const& a_vecsResource, size_t a_producersNum)
{
	//TODO - add a checking of how many cpu i have ??

	for(auto& v : a_vecsResource)
	{
		if(a_producersNum == 0)
		{
			break;
		}

		a_threadsVec.push_back(std::thread(&SafeQueue<IV>::enqueue, std::ref(a_sq), std::ref(v)));
		-- a_producersNum;
	}
}
void add_consumers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_consumersNum)
{
	//TODO - add a checking of how many cpu i have ??

	auto safe_pop = [&a_sq]()
	{
		IV a_vec;
		a_sq.dequeue(a_vec);
		std::cout << "wait dequeue was called\n\n";
	};

	while(a_consumersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(safe_pop));
	}
}
*/

void join_all_threads(std::vector<std::thread>& a_threadsVec)
{
	for(auto& t : a_threadsVec)
	{
		t.join();
	}
}

int main(int argc, char* argv[])
{
	SafeQueue<IV> sq;

		std::cout << "start - the queue size is: " << sq.size() << "\n\n";

	std::vector<IV> resource = generate_vec_of_vecs(30);

	std::vector<std::thread> threadsVec;
	IV vec;

	add_consumers(sq, threadsVec, std::stoi(argv[2]), 20);
	add_producers(sq, threadsVec, std::stoi(argv[1]), 20);

	join_all_threads(threadsVec);	

	std::cout << "end - the queue size is: " << sq.size() << '\n';

//	que_print(sq);

	return 0;
}