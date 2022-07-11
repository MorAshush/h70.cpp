#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <time.h>

#include "mu_test.h"
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

std::vector<std::thread>& create_threads_vector(SafeQueue<IV>& a_sq, std::vector<IV>const& a_vecsResource, std::vector<std::thread>& a_threadsVec, size_t a_threadsNum)
{
	//TODO - add a checking of how many cpu i have ??

	for(auto& v : a_vecsResource)
	{
		if(a_threadsNum == 0)
		{
			break;
		}

		a_threadsVec.push_back(std::thread(&SafeQueue<IV>::enqueue, std::ref(a_sq), std::ref(v)));
		-- a_threadsNum;
	}

	return a_threadsVec;
}


BEGIN_TEST(equal_consumers_and_producers)

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

	TEST(equal_consumers_and_producers)
	TEST(more_producers_than_consumers)
	TEST(more_consumers_than_producers)
	TEST(only_consumers_until_que_is_empty)


END_SUITE