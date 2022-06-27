#include <functional>
#include <iostream>
#include <vector>
#include <iterator>

auto sum(std::vector<int>::const_iterator a_it, std::vector<int>::const_iterator a_end, bool(*predicate)(int))
{
	int sum = 0;
	while(a_it != a_end)
	{
		if(predicate(*a_it))
		{
			sum += *a_it;
		}

		++a_it;
	}

	return sum;
}

/*
auto even_sum(std::vector<int> const& a_v, bool(*predicate)(int))
{
	int sum = 0;
	for(auto i : a_v)
		if(predicate(i))
		{
			sum += i;
		}

	for(auto i : a_v)
		std::cout << i << ' ';
	std::cout << '\n';

	return sum;
}
*/

auto do_operation(std::vector<int>::iterator a_it, std::vector<int>::iterator a_end, void(*inflate)(int&))
{
	while(a_it != a_end)
	{
		inflate(*a_it);

		++a_it;
	}
}

int main()
{
	std::vector<int> v;
	v.reserve(10);
	for(size_t i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}

	std::cout << "before operations: " << '\n';
	for(auto i : v)
		std::cout << i << ' ';
	std::cout << "\n\n";

	int sum = even_sum(v.cbegin(), v.cend(), [](int a_num) {return (a_num % 2) == 0;});

	std::cout << "sum of even numbers: " << sum << "\n\n";

	std::cout << "after inflation: " << '\n';
	do_operation(v.begin(), v.end(), [](int& a_num) {a_num *= 10;});

	for(auto i : v)
		std::cout << i << ' ';
	std::cout << "\n\n";

	return 0;
}