#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>
#include <cassert>

#include "mu_test.h"
#include "thread_safe_queue.hpp"

//typedef std::vector<int64_t> IV;

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

void add_fifo_producers(SafeQueue<std::pair<size_t, int>>& a_sq, std::vector<std::thread>& a_threadsVec, 
																size_t a_producersNum, size_t a_numOfInserts)
{
	auto fifo_producer = [&a_sq](size_t a_threadNum, size_t a_numOfInserts)
	{
		size_t innerSerialNum = 0;

		while(a_numOfInserts-- > 0)
		{
			std::pair<size_t, int> p(a_threadNum, innerSerialNum);
			a_sq.enqueue(std::move(p));
			++innerSerialNum;
		}
	};

	size_t threadNum = 1;
	while(a_producersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(fifo_producer, threadNum, a_numOfInserts));
		++threadNum;
	}
}
/*
typedef size_t threadID;
typedef std::vector<std::pair<size_t, int>> pairsVector;
typedef std::map<threadID, pairsVector* > mappedPoppings;

void add_fifo_consumers(SafeQueue<std::pair<size_t, int>>& a_sq, std::vector<std::thread>& a_threadsVec, 
						mappedPoppings& a_map, size_t a_consumersNum, size_t a_numOfPops)
{
	auto fifo_consumer = [&a_sq, &a_map](size_t a_numOfPops)
	{
		while(a_numOfPops-- > 0)
		{
			std::pair<threadID, int> p;
			a_sq.dequeue(p);

//			asserting that map's size fits the num of PRODUCERS, so each thread gets a vector to contain it's popped pairs
			auto vp = a_map[p->first];
			vp->push_back(p);
		}
	};

	size_t i = 0;

	while(a_consumersNum-- > 0)
	{
		a_threadsVec.push_back(std::thread(fifo_consumer, a_numOfPops, i));
		++i;
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

BEGIN_TEST(check_fifo_one_producer_one_consumers)

	SafeQueue<int64_t> sq(10000);
	std::vector<std::thread> threadsVec;

	std::vector<std::vector<int64_t>> vecOfPoppedVecs;

//	add_fifo_consumers(sq, threadsVec, vecOfPoppedVecs, 2, 1);


	ASSERT_PASS();

END_TEST

BEGIN_TEST(check_fifo_one_producer_two_consumers)

	SafeQueue<int64_t> sq(10000);
	std::vector<std::thread> threadsVec;
	std::vector<std::vector<int64_t>> vecOfPoppedVecs;

//	add_fifo_consumers(sq, threadsVec, vecOfPoppedVecs, 2, 1);


	ASSERT_PASS();

END_TEST

BEGIN_TEST(consumers_as_many_as_producers)

	SafeQueue<int64_t> sq(1000000);

	std::vector<std::thread> threadsVec;
	threadsVec.reserve(40);

	size_t initialSize = sq.size();

	add_producers(sq, threadsVec, 20, 10000);
	add_consumers(sq, threadsVec, 20, 10000);

	join_all_threads(threadsVec);	

	size_t finalSize = sq.size();

	ASSERT_EQUAL(initialSize, finalSize);

END_TEST

BEGIN_TEST(more_producers_than_consumers_1)

	SafeQueue<int64_t> sq(1000000);

	std::vector<std::thread> threadsVec;
	threadsVec.reserve(30);

	add_producers(sq, threadsVec, 20, 10000);
	add_consumers(sq, threadsVec, 10, 10000);

	join_all_threads(threadsVec);	

	size_t finalSize = sq.size();

	ASSERT_EQUAL(finalSize, 100'000);

END_TEST

BEGIN_TEST(more_producers_than_consumers_2)

	SafeQueue<int64_t> sq(1000000);

	std::vector<std::thread> threadsVec;
	threadsVec.reserve(40);

	add_producers(sq, threadsVec, 20, 10000);
	add_consumers(sq, threadsVec, 20, 5000);

	join_all_threads(threadsVec);	

	size_t finalSize = sq.size();

	ASSERT_EQUAL(finalSize, 100'000);

END_TEST

BEGIN_TEST(only_consumers_until_que_is_empty)

	ASSERT_PASS();

END_TEST




BEGIN_SUITE(test)

	TEST(consumers_as_many_as_producers)
	TEST(more_producers_than_consumers_1)
	TEST(more_producers_than_consumers_2)


END_SUITE