#include <cstddef>
#include <string>
#include <cmath>
#include <iostream>
#include <iterator>
#include <stdlib.h>

#include "my_algorythems.hpp"
#include "person.hpp"
#include "point.hpp"


namespace my_algorythems
{

std::list<objects::Person>& sort_by_name(std::list<objects::Person>& a_list)
{
	if(a_list.size() == 1)
	{
		return a_list;
	}

	bool wasSwap = 1;

	while(wasSwap)
	{
		std::list<objects::Person>::iterator first_it = a_list.begin();
		std::list<objects::Person>::iterator second_it = ++a_list.begin();
		wasSwap = 0;

		while(second_it != a_list.end())
		{
			if(first_it->name() > second_it->name())
			{
				objects::swap_persons(*first_it, *second_it);
				wasSwap = 1;	
			}
			
			first_it++;
			second_it++;			
		}

		if(wasSwap == 0)
		{
			break;
		}
	}

	return a_list;
}

void print_list(std::list<objects::Person> a_list) 
{
	std::list<objects::Person>::iterator it = a_list.begin();
	std::list<objects::Person>::iterator end = a_list.end();

	std::cout << "[";

	while(it != end)
	{
		std::cout << it->name();

		std::cout << ",";

		it++;
	}

	std::cout << "]";
}

void print_vec(std::vector<coordinates::Point> a_vector) 
{
	std::vector<coordinates::Point>::iterator it = a_vector.begin();
	std::vector<coordinates::Point>::iterator end = a_vector.end();

	std::cout << "[";

	while(it != end)
	{
		std::cout << it->distance_from_point_zero();

		std::cout << ",";

		it++;
	}

	std::cout << "]";
}


std::vector<int> random_int_vector(size_t a_n, int a_upper)
{
	std::vector<int> v;
	v.reserve(a_n);

	for(size_t i = 0; i < a_n; ++i)
	{
		int randNum = rand() % a_upper;
		v.push_back(randNum);
	}

	return v;
}

/*
bool Obesity::operator()(objects::Person const& a_person)
{
	return is_obese(a_person);
}
template <typename T>
bool operator()(T const& a_first, T const& a_second)
{
	return a_first > a_second;
}
*/
}//namespace my_elgorythems