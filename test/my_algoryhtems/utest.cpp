#include <cstddef>
#include <cmath>
#include <iostream>
#include <string>
#include <list>

#include "mu_test.h"
#include "person.hpp"
#include "point.hpp"
#include "my_algorythems.hpp"

//not generic
BEGIN_TEST(sort_list_of_persons_test)	

	std::list<objects::Person> l;

	objects::Person p1("111111", "c", 75, 182);
	objects::Person p2("222222", "d", 70, 165);
	objects::Person p3("333333", "a", 78, 167);
	objects::Person p4("444444", "b", 78, 167);
	objects::Person p5("555555", "e", 78, 167);
	objects::Person p6("666666", "k", 78, 167);
	objects::Person p7("777777", "j", 78, 167);
	objects::Person p8("888888", "i", 78, 167);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	l.push_back(p7);
	l.push_back(p8);

	my_algorythems::sort_by_name(l);

	ASSERT_EQUAL(l.begin()->name(), "a");
	ASSERT_EQUAL(l.rbegin()->name(), "k");

END_TEST

BEGIN_TEST(sort_list_of_persons_test_with_one_element)	

	std::list<objects::Person> l;

	objects::Person p1("111111", "c", 75, 182);
	
	l.push_back(p1);

	my_algorythems::sort_by_name(l);

	ASSERT_EQUAL(l.begin()->name(), "c");

END_TEST

//generic bubble sort

bool compare_int(int a_first, int a_second)
{
	return a_first > a_second;
}

BEGIN_TEST(gen_bubble_sort_vector_of_ints_with_one_element)	

	std::vector<int> v;

	v.push_back(20);

	my_algorythems::gen_bubble_sort(v, compare_int);

	ASSERT_EQUAL(my_algorythems::is_sorted(v, compare_int), 1);

END_TEST

BEGIN_TEST(gen_bubble_sort_vector_of_ints)	

	std::vector<int> v = my_algorythems::random_int_vector(10, 50);
	
	my_algorythems::gen_bubble_sort(v, compare_int);

	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ',';
	}
	std::cout << '\n';

	ASSERT_EQUAL(my_algorythems::is_sorted(v, compare_int), 1);

END_TEST

bool compare_strings(std::string a_first, std::string a_second)
{
	return a_first > a_second;
}

BEGIN_TEST(gen_bubble_sort_vector_of_strings)	

	std::vector<std::string> v;
	v.reserve(10);

	v.push_back("aaaa");
	v.push_back("bbbb");
	v.push_back("cc");
	v.push_back("ddd");
	v.push_back("aabb");
	v.push_back("y");
	v.push_back("m");
	v.push_back("ml");
	v.push_back("ooo");
	v.push_back("z");

	my_algorythems::gen_bubble_sort(v, compare_strings);

	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ',';
	}
	std::cout << '\n';

	ASSERT_EQUAL(my_algorythems::is_sorted(v, compare_strings), 1);

END_TEST


bool compare_points(coordinates::Point a_first, coordinates::Point a_second)
{
	return a_first > a_second;
}

BEGIN_TEST(gen_bubble_sort_vector_of_points_with_one_element)	

	std::vector<coordinates::Point> v;

	coordinates::Point p(2, 5);

	v.push_back(p);

	my_algorythems::gen_bubble_sort(v, compare_points);
	bool result = my_algorythems::is_sorted(v, compare_points);

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(gen_bubble_sort_vector_of_points)	

	std::vector<coordinates::Point> v;

	v.reserve(5);

	coordinates::Point p1(15, 15);
	coordinates::Point p2(6, 7);
	coordinates::Point p3(5, 18);
	coordinates::Point p4(13, 20);
	coordinates::Point p5(30, 8);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	my_algorythems::gen_bubble_sort(v, compare_points);
	bool result = my_algorythems::is_sorted(v, compare_points);
	
	my_algorythems::print_vec(v);
	std::cout << '\n';


	ASSERT_EQUAL(result, 1);

END_TEST

bool is_positive(int a_num)
{
	return a_num >= 0;
}

BEGIN_TEST(partition_on_vector_ints_with_sign_criteria)

	std::vector<int> v;
	v.reserve(10);
	v.push_back(-5);
	v.push_back(2);
	v.push_back(-10);
	v.push_back(8);
	v.push_back(-13);
	v.push_back(30);
	v.push_back(-17);
	v.push_back(35);
	v.push_back(0);
	v.push_back(15);
	
	my_algorythems::gen_container_partition(v, is_positive);

	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ',';
	}
	std::cout << '\n';

	ASSERT_PASS();

END_TEST

bool is_even(int a_num)
{
	return (a_num % 2) == 0;
}

BEGIN_TEST(partition_on_vector_ints_with_odd_criteria)

	std::vector<int> v;
	v.reserve(10);
	v.push_back(-5);
	v.push_back(2);
	v.push_back(-10);
	v.push_back(8);
	v.push_back(-13);
	v.push_back(30);
	v.push_back(-17);
	v.push_back(35);
	v.push_back(0);
	v.push_back(15);
	
	my_algorythems::gen_container_partition(v, is_even);

	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ',';
	}

	std::cout << '\n';

	ASSERT_PASS();

END_TEST

bool is_obese(objects::Person const& a_person)
{
	double bmi = a_person.body_mass() / pow(static_cast<double>(a_person.height()) / 100, 2);
	return bmi > 25;
}

BEGIN_TEST(partition_on_vector_persons_with_bmi_criteria)

	std::vector<objects::Person> v;
	v.reserve(9);
	
	objects::Person p1("11111", "maxim", 67, 165);
	objects::Person p2("22222", "mor", 50, 163);
	objects::Person p3("33333", "yarden", 67, 170);
	objects::Person p4("44444", "dina", 53, 165);
	objects::Person p5("55555", "lea", 70, 160);
	objects::Person p6("66666", "oz", 13, 90);
	objects::Person p7("77777", "carmel", 11, 55);
	objects::Person p8("88888", "negev", 17, 100);
	objects::Person p9("99999", "sini", 13, 70);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	v.push_back(p8);
	v.push_back(p9);
	
	my_algorythems::gen_container_partition(v, is_obese);

	for(size_t i = 0; i < v.size(); ++i)
	{
		double bmi = v[i].body_mass() / pow(static_cast<double>(v[i].height()) / 100, 2);

		std::cout << bmi << ',';
	}
	std::cout << '\n';

	ASSERT_PASS();

END_TEST
/*
BEGIN_TEST(find_last_element_of_specific_criteria)

	std::vector<int> v;
	v.reserve(10);
	v.push_back(-5);
	v.push_back(2);
	v.push_back(-10);
	v.push_back(8);
	v.push_back(-13);
	v.push_back(30);
	v.push_back(-17);
	v.push_back(35);
	v.push_back(0);
	v.push_back(15);
	
	int result = my_algorythems::find_last_of_criteria(v, is_positive);

	for(size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ',';
	}

	ASSERT_EQUAL(result, 15);

END_TEST
*/
BEGIN_SUITE(my algorythems)

	TEST(sort_list_of_persons_test)
	TEST(sort_list_of_persons_test_with_one_element)

	TEST(gen_bubble_sort_vector_of_ints_with_one_element)
	TEST(gen_bubble_sort_vector_of_ints)
	TEST(gen_bubble_sort_vector_of_points_with_one_element)
	TEST(gen_bubble_sort_vector_of_strings)
	TEST(gen_bubble_sort_vector_of_points)

	TEST(partition_on_vector_ints_with_sign_criteria)
	TEST(partition_on_vector_ints_with_odd_criteria)
	TEST(partition_on_vector_persons_with_bmi_criteria)

//	TEST(find_last_element_of_specific_criteria)

END_SUITE

