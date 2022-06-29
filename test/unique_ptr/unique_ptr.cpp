#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "rational.hpp"

size_t partition(std::vector<std::unique_ptr<algebra::Rational>>& a_vector, size_t a_left, size_t a_right)
{
	std::unique_ptr<algebra::Rational> pivot = std::move(a_vector[a_right]);

	while(a_left < a_right)
	{
		algebra::Rational l = *a_vector[a_left];

		algebra::Rational r = *a_vector[a_right];

		algebra::Rational p = *pivot;

		if((l > p) && (r <= p))
		{
			a_vector[a_left].swap(a_vector[a_right]);
		}

		if(l <= p)
		{
			++a_left;
		}

		if(r > p)
		{
			--a_right;
		}

		a_vector[a_right].swap(pivot);
	}

	return a_right;
}

void quick_sort(std::vector<std::unique_ptr<algebra::Rational>>& a_vector, size_t a_left, size_t a_right)
{
	size_t n = a_vector.size();
	if(!n || n == 1)
	{
		return;
	}

	size_t pivot = partition(a_vector, a_left, a_right);
	quick_sort(a_vector, a_left, pivot - 1);
	quick_sort(a_vector, pivot + 1, a_right);
}

void vector_print(std::vector<std::unique_ptr<algebra::Rational>> const& a_vector)
{
	size_t size = a_vector.size();

	for(size_t i = 0; i < size; ++i)
	{
		algebra::Rational rational = *a_vector[i];
		rational.print();
	}

	std::cout << '\n';
}


int main()
{
	std::vector<std::unique_ptr<algebra::Rational>> vec;

	std::unique_ptr<algebra::Rational> p1(new algebra::Rational(10, 2));
	std::unique_ptr<algebra::Rational> p2(new algebra::Rational(2, 6));
	std::unique_ptr<algebra::Rational> p3(new algebra::Rational(15, 8));
	std::unique_ptr<algebra::Rational> p4(new algebra::Rational(1, 10));
	
	vec.push_back(std::move(p1));

	if(vec[0] == nullptr)
	{
		std::cout << "ptr is null\n";
	}

	vec.push_back(std::move(p2));
	vec.push_back(std::move(p3));
	vec.push_back(std::move(p4));


/*	std::vector<std::unique_ptr<algebra::Rational>> vec;

	for(size_t i = 0; i < 10; ++i)
	{
		vec.push_back( std::unique_ptr<algebra::Rational>(new algebra::Rational(rand() % 20, rand() % 30)) );
		
	}
*/
	std::cout << "before\n";
	vector_print(vec);

	quick_sort(vec, 0, vec.size() - 1);

	std::cout << "after\n";
	vector_print(vec);


	return 0;
}