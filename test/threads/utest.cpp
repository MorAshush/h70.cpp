#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>

#include "thread_safe_queue.hpp"

typedef std::vector<int64_t> IV;

void enque_work(SafeQueue<int64_t>& a_sq, size_t a_numOfTimes)
{
	size_t i = 0;
	while(a_numOfTimes-- > 0)
	{
		int64_t t = i;
		a_sq.enqueue(t);
		++i;
	}
}

void deque_work(SafeQueue<int64_t>& a_sq, size_t a_numOfTimes)
{
	while(a_numOfTimes-- > 0)
	{
		int64_t t;
		a_sq.dequeue(t);
	}
}

void add_producers(SafeQueue<int64_t>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_producersNum, size_t a_numOfInserts)
{
	while(a_producersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(enque_work, std::ref(a_sq), a_numOfInserts));
	}
}

void add_consumers(SafeQueue<int64_t>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_consumersNum, size_t a_numOfPops)
{
	while(a_consumersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(deque_work, std::ref(a_sq), a_numOfPops));
	}
}

void join_all_threads(std::vector<std::thread>& a_threadsVec)
{
	for(auto& t : a_threadsVec)
	{
		t.join();
	}
}

int main(int argc, char* argv[])
{
	SafeQueue<int64_t> sq(1000000);

		std::cout << "start - the queue size is: " << sq.size() << "\n\n";

	std::vector<std::thread> threadsVec;

	add_producers(sq, threadsVec, std::stoi(argv[1]), 50000);
	add_consumers(sq, threadsVec, std::stoi(argv[2]), 50000);

	join_all_threads(threadsVec);	

	std::cout << "end - the queue size is: " << sq.size() << '\n';

//	que_print(sq);

	return 0;
}