#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


void swap(std::vector<int>& a_first, std::vector<int>& a_second)
{
	auto t = std::move(a_first);
	a_first = std::move(a_second);
	a_second = std::move(t);
}

int sum_elements(std::vector<int> const& a_vec)
{
	int sum = 0;
	for(auto i : a_vec)
	{
		sum += i;
	}

	return sum;
}

std::vector<int> calc_elements_sum(std::vector<std::vector<int>> const& a_vec)
{
	size_t size = a_vec.size();

	std::vector<int> sums;
	sums.reserve(size);

	for(size_t i = 0; i < size; ++i)
	{
		sums[i] = sum_elements(a_vec[i]);
	}

	return sums;
}

void bubble_sort(std::vector<std::vector<int>>& a_vec, std::vector<int>& a_sums)
{
	size_t vecSize = a_vec.size();

	if(vecSize < 2)
	{
		return ;
	}

	bool wasSwap = 0;

	for(size_t i = 0; i < vecSize - 1; ++i)
	{
		wasSwap = 0;

		for(size_t j = 0; j < vecSize - i - 1; ++j)
		{
			auto sumLeft = a_sums[j];
			auto sumRight = a_sums[j + 1];

			std::cout << sumLeft << '|' << sumRight << "\n\n";

			if(sumLeft > sumRight)
			{
				wasSwap = 1;
				swap(a_vec[j], a_vec[j + 1]);
				std::swap(a_sums[j], a_sums[j + 1]);
			}
		}

		if(wasSwap == 0)
		{
			break;
		}
	}
}

void print_vec_of_vecs(std::vector<std::vector<int>> const& a_vec)
{
	for(auto i : a_vec)
	{
		std::cout << sum_elements(i) << ", ";
	}

	std::cout << "\n\n";
}

std::vector<std::vector<int>> generate_vec_of_vecs()
{
	std::vector<std::vector<int>> vv;
	size_t size = rand() % 30 + 15;
	vv.reserve(size);

	for(size_t i = 0; i < size; ++i)
	{
		int randCapacity = rand() % 100 + 1;
		int randInitValue = rand() % 30;

		std::vector<int> n(randCapacity, randInitValue);
		vv.push_back(std::move(n));
 	}

 	return vv;
}

int main()
{
	std::vector<std::vector<int>> vv = generate_vec_of_vecs();

	auto sums = calc_elements_sum(vv);

	print_vec_of_vecs(vv);

	bubble_sort(vv, sums);

	print_vec_of_vecs(std::move(vv));
	return 0;
}