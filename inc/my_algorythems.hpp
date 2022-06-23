#ifndef MY_ALGORYTHEMS_HPP
#define MY_ALGORYTHEMS_HPP

#include <vector>
#include <cstddef>
#include <iostream>


#include "person.hpp"
#include "point.hpp"


namespace my_algorythems
{

std::list<objects::Person>& sort_by_name(std::list<objects::Person>& a_list);

void print_list(std::list<objects::Person> a_list) ;
void print_vec(std::vector<coordinates::Point> a_vector) ;

/*
template <typename C>
std::ostream& operator<<(std::ostream& a_os, C const& a_container)
{
	typename C::iterator it = a_container.begin();
	typename C::iterator end = a_container.end();

	while(it != end)
	{
		a_os << *it;
		++it;
	}

	return a_os;
}
*/
template <typename C, typename F>
C& gen_bubble_sort(C& a_container, F a_cmpFunc)
{
	bool wasSwap = 1;

	while(wasSwap)
	{
		typename C::iterator first_it = a_container.begin();
		typename C::iterator second_it = ++a_container.begin();
		wasSwap = 0;

		while(second_it != a_container.end())
		{
			if(a_cmpFunc(*first_it, *second_it))
			{
				using std::swap;
				swap(*first_it, *second_it);
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

	return a_container;
}


template <typename C, typename F>
C& gen_container_partition(C& a_container, F a_criteriaFunc)
{
	typename C::iterator it = a_container.begin();
	typename C::reverse_iterator rev_it = a_container.rbegin();

	while(it != rev_it.base())
	{		
		if(a_criteriaFunc(*it)) //current it needs to move on the right side
		{
			using std::swap;
			swap(*it, *rev_it);
			rev_it++;
		}
		else //if current it stays on the left side 
		{
			it++;
		}		
	}

	return a_container;
}


template <typename T, typename C, typename F>
T find_last_of_criteria(C& a_container, F a_criteriaFunc)
{
	typename C::iterator rev_end = a_container.rend();
	typename C::reverse_iterator rev_it = a_container.rbegin();

	while(rev_it != rev_end)
	{		
		if(a_criteriaFunc(*rev_it)) //current is the last element that fulfill the criteria
		{
			return rev_it;
		}
		else //move to next iterator 
		{
			rev_it++;
		}		
	}

	return a_container.end();
}


template <typename C, typename CMP>
bool is_sorted(C& a_container, CMP a_cmpFunc)
{
	if(a_container.size() == 1)
	{
		return true;
	}

	typename C::iterator first = a_container.begin();
	typename C::iterator second = ++a_container.begin();
	typename C::iterator end = a_container.end();

	while(second != end)
	{
		if(a_cmpFunc(*first, *second))
		{
			return false;
		}

		++first;
		++second;
	}

	return true;
}

template <typename C, typename F>
bool is_sorted(typename C::iterator a_begin, typename C::iterator a_end, F a_cmpFunc)
{
	typename C::iterator second = ++a_begin;

	while(second != a_end)
	{
		if(a_cmpFunc(*a_begin, *second))
		{
			return false;
		}

		++a_begin;
		++second;
	}

	return true;
}

std::vector<int> random_int_vector(size_t a_n, int a_upper);

template <typename T>
struct cmp
{
	bool operator()(T const& a_first, T const& a_second);
};

}//namespace my_algorythems















#endif //MY_ALGORYTHEMS_HPP