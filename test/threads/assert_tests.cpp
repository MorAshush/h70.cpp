#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>

#include "mu_test.h"
#include "thread_safe_queue.hpp"

typedef std::vector<int64_t> IV;

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
void fifo_producers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, size_t a_producersNum, size_t a_numOfInserts)
{
	auto fifo_producer = [&a_sq](size_t a_numOfInserts, size_t a_storingIndex)
	{
		while(a_numOfInserts-- > 0)
		{
			IV t(1000, 1);
			a_sq.enqueue(std::move(t));

			//insert each enqueued vec the num of thread, sequence in que, and thread inner sequence?
		}
	};
}
*/
void fifo_consumers(SafeQueue<IV>& a_sq, std::vector<std::thread>& a_threadsVec, std::vector<std::vector<IV>>& a_vecOfPoppedVecs, 
																			size_t a_consumersNum, size_t a_numOfPops)
{
	a_vecOfPoppedVecs.reserve(a_consumersNum);

	auto fifo_consumer = [&a_sq, &a_vecOfPoppedVecs](size_t a_numOfPops, size_t a_storingIndex)
	{
		while(a_numOfPops-- > 0)
		{
			IV t;
			a_sq.dequeue(t);
			a_vecOfPoppedVecs[a_storingIndex].push_back(std::move(t));
		}
	};

	size_t i = 0;

	while(a_consumersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(fifo_consumer, a_numOfPops, i));
		++i;
	}
}

void join_all_threads(std::vector<std::thread>& a_threadsVec)
{
	for(auto& t : a_threadsVec)
	{
		t.join();
	}
}

/*
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
*/

BEGIN_TEST(check_fifo_one_producer_two_consumers)

	SafeQueue<IV> sq;
	std::vector<std::thread> threadsVec;
	std::vector<std::vector<IV>> vecOfPoppedVecs;

	fifo_consumers(sq, threadsVec, vecOfPoppedVecs, 2, 1);


	ASSERT_PASS();

END_TEST


BEGIN_TEST(more_producers_than_consumers)

	ASSERT_PASS();

END_TEST

BEGIN_TEST(more_consumers_than_producers)

	ASSERT_PASS();

END_TEST

BEGIN_TEST(only_consumers_until_que_is_empty)

	ASSERT_PASS();

END_TEST




BEGIN_SUITE(test)

	TEST(more_producers_than_consumers)
	TEST(more_consumers_than_producers)
	TEST(only_consumers_until_que_is_empty)


END_SUITE