#include <iostream>
#include <cstdlib>
#include <time.h>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

void add(int64_t& a_base, int64_t a_num)
{
	a_base += a_num;
}

int64_t sum_vector(std::vector<int64_t>const& a_vector)
{    
    int64_t sum = 0;

    std::mutex mtx;

    auto calc_half = [&sum, &mtx, &a_vector](size_t startIndex, size_t endIndex)
    { 
		for(size_t i = startIndex; i < endIndex; ++i)
		{
		    mtx.lock();
		    add(sum, a_vector[i]);
		    mtx.unlock();
		}
	};

	std::thread t1(calc_half, 0, a_vector.size() / 2);
    std::thread t2(calc_half, a_vector.size() / 2, a_vector.size());

    t1.join();
    t2.join();

    std::cout << "vector sum: " << sum << '\n';
    return sum;
}

void store_max(int64_t& a_max, int64_t a_num)
{
	if(a_max < a_num)
	{
		a_max = a_num;
	}
}

int64_t find_max_element(std::vector<int64_t>const& a_vector)
{    
    int64_t max = a_vector[0];

    std::mutex mtx;

    auto search_half = [&max, &mtx, &a_vector](size_t startIndex, size_t endIndex)
    { 
		for(size_t i = startIndex; i < endIndex; ++i)
		{
		    mtx.lock();
		    store_max(max, a_vector[i]);
		    mtx.unlock();
		}
	};

	std::thread t1(search_half, 0, a_vector.size() / 2);
    std::thread t2(search_half, a_vector.size() / 2, a_vector.size());

    t1.join();
    t2.join();

    std::cout << "vector max value: " << max << '\n';
    return max;
}

int main()
{
	std::vector<int64_t> vec1(1000000, 10);
	sum_vector(vec1);

	srand(time(0));

	std::vector<int64_t> vec2(30, 0);

	for(size_t i = 0; i < 30; ++i)
	{
		vec2[i] = rand() % 2000;
	}

	for(auto i : vec2)
	{
		std::cout << i << ", ";
	}
	std::cout << '\n';

	find_max_element(vec2);

	return 0;
}