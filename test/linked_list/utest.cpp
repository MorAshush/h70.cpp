#include "mu_test.h"

#include "slist.hpp"

class printer
{	
public:
	printer();

	void print(int a_data);
	void operator()(int a_data);
};

printer::printer()
{
}

void printer::print(int a_data)
{
	printf("%d ", a_data);
}


void printer::operator()(int a_data)
{
	print(a_data);
}


class multiplier
{	
private:
	int m_factor;

public:
	multiplier(int a_factor);

	void multiply(int& a_data);

	void operator()(int& a_data);
};

multiplier::multiplier(int a_factor)
: m_factor(a_factor)
{
}

void multiplier::multiply(int& a_data)
{
	a_data *= m_factor;
}


void multiplier::operator()(int& a_data)
{
	multiply(a_data);
}



BEGIN_TEST(list_ctor_test)	

	adt::SingleLinkedList<int> list;
	
	ASSERT_EQUAL(list.size(), 0);

END_TEST

BEGIN_TEST(list_append_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	list.print();

	ASSERT_EQUAL(list.size(), 6);
	ASSERT_THAT(list.front() == 10);
	ASSERT_THAT(list.back() == 60);

END_TEST

BEGIN_TEST(list_to_list_append_test)

	adt::SingleLinkedList<int> list1;
	list1.append(10);
	list1.append(20);
	list1.append(30);

	adt::SingleLinkedList<int> list2;
	list2.append(40);
	list2.append(50);
	list2.append(60);

	list1.append(list2);

	list1.print();

	ASSERT_EQUAL(list1.size(), 6);
	ASSERT_THAT(list1.front() == 10);
	ASSERT_THAT(list1.back() == 60);

END_TEST

BEGIN_TEST(list_prepend_test)	

	adt::SingleLinkedList<int> list;
	list.prepend(10);
	list.prepend(20);
	list.prepend(30);
	list.prepend(40);
	list.prepend(50);
	list.prepend(60);

	list.print();

	ASSERT_EQUAL(list.size(), 6);
	ASSERT_THAT(list.front() == 60);
	ASSERT_THAT(list.back() == 10);

END_TEST

BEGIN_TEST(list_to_list_prepend_test)	

	adt::SingleLinkedList<int> list1;
	list1.append(10);
	list1.append(20);
	list1.append(30);

	adt::SingleLinkedList<int> list2;
	list2.append(40);
	list2.append(50);
	list2.append(60);

	list1.prepend(list2);

	ASSERT_EQUAL(list1.size(), 6);
	ASSERT_THAT(list1.front() == 40);
	ASSERT_THAT(list1.back() == 30);

END_TEST

BEGIN_TEST(remove_front_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	int data = list.remove_front();
	list.print();

	ASSERT_THAT(data == 10);
	ASSERT_EQUAL(list.size(), 5);

END_TEST

BEGIN_TEST(remove_back_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	int data = list.remove_back();
	list.print();

	ASSERT_THAT(data == 60);
	ASSERT_EQUAL(list.size(), 5);

END_TEST

BEGIN_TEST(operator_smaller_than__test1)	

	adt::SingleLinkedList<int> list1;
	list1.append(10);
	list1.append(20);
	list1.append(30);

	adt::SingleLinkedList<int> list2;
	list2.append(40);
	list2.append(50);
	list2.append(60);

	int result = list1 < list2;

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(operator_smaller_than__test2)	

	adt::SingleLinkedList<int> list1;
	list1.append(10);
	list1.append(20);
	list1.append(30);
	list1.append(40);

	adt::SingleLinkedList<int> list2;
	list2.append(40);
	list2.append(50);
	list2.append(60);

	int result = list1 < list2;

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(operator_smaller_than__test3)	

	adt::SingleLinkedList<int> list1;
	list1.append(40);
	list1.append(50);
	list1.append(60);

	adt::SingleLinkedList<int> list2;
	list2.append(10);
	list2.append(20);
	list2.append(30);
	list2.append(40);

	int result = list1 < list2;

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(operator_is_bigger_than_test1)	

	adt::SingleLinkedList<int> list1;
	list1.append(40);
	list1.append(50);
	list1.append(60);

	adt::SingleLinkedList<int> list2;
	list2.append(10);
	list2.append(20);
	list2.append(30);
	list2.append(40);

	int result = list1 > list2;

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(operator_is_bigger_than_test2)	

	adt::SingleLinkedList<int> list1;
	
	list1.append(10);
	list1.append(20);
	list1.append(30);
	list1.append(40);

	adt::SingleLinkedList<int> list2;
	
	list2.append(40);
	list2.append(50);
	list2.append(60);

	list1.print();
	list2.print();

	int result = list1 > list2;

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(operator_is_equal_test1)	

	adt::SingleLinkedList<int> list1;
	
	list1.append(10);
	list1.append(20);
	list1.append(30);
	list1.append(40);

	adt::SingleLinkedList<int> list2;
	
	list2.append(40);
	list2.append(50);
	list2.append(60);

	int result = list1 == list2;

	ASSERT_EQUAL(result, 0);

END_TEST

BEGIN_TEST(operator_is_equal_test2)	

	adt::SingleLinkedList<int> list1;
	
	list1.append(40);
	list1.append(50);
	list1.append(60);

	adt::SingleLinkedList<int> list2;
	
	list2.append(40);
	list2.append(50);
	list2.append(60);

	int result = list1 == list2;

	ASSERT_EQUAL(result, 1);

END_TEST

BEGIN_TEST(reverse_list_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	list.append(70);

	list.reverse();
	list.print();

	ASSERT_THAT(list.front() == 70);
	ASSERT_THAT(list.back() == 10);	

END_TEST

BEGIN_TEST(list_begin_function_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);

	ASSERT_THAT(list.begin().get_data() == 10);
	ASSERT_THAT(*(list.begin()) == 10);

END_TEST

BEGIN_TEST(list_end_function_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);

	ASSERT_THAT(list.end().get_data() == 0);

END_TEST

BEGIN_TEST(iterator_get_data_function_test1)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	list.append(70);

	ASSERT_THAT((++list.begin()).get_data() == 20);
	ASSERT_EQUAL((++(++list.begin())).get_data() , 30);

END_TEST

BEGIN_TEST(iterator_get_data_function_test2)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	list.append(70);

	adt::ListItr<int> current = list.begin();
	for(int i = 0; i < 3; ++i)
	{
		++current;
	}

	ASSERT_EQUAL(current.get_data(), 40);
	ASSERT_EQUAL(*current , 40);

END_TEST

BEGIN_TEST(iterator_set_data_function_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);

	adt::ListItr<int> current = list.begin();
	for(int i = 0; i < 3; ++i)
	{
		++current;
	}

	int x = 100;
	current.set_data(x);
	ASSERT_EQUAL(current.get_data(), 100);

	x = 200;
	*current = x;
	ASSERT_EQUAL(current.get_data(), 200);

END_TEST

BEGIN_TEST(iterator_isEqual_operator_test1)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);

	adt::ListItr<int> first = ++list.begin();
	adt::ListItr<int> second = ++list.begin();

	int result = first == second;
	
	ASSERT_EQUAL(result, 1);
	ASSERT_EQUAL(first.get_data(), 20);
	ASSERT_EQUAL(second.get_data(), 20);

END_TEST

BEGIN_TEST(iterator_isEqual_operator_test2)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);

	adt::ListItr<int> first = ++list.begin();
	adt::ListItr<int> second = ++(++list.begin());

	int result = first == second;
	
	ASSERT_EQUAL(result, 0);
	ASSERT_EQUAL(first.get_data(), 20);
	ASSERT_EQUAL(second.get_data(), 30);

END_TEST

//////////////////////////////////////////////////////////////////////////////////////////////
/*
BEGIN_TEST(constIterator_get_data_function_test1)	

	const adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	list.append(70);

	ASSERT_THAT((++list.begin()).get_data() == 20);
	ASSERT_EQUAL((++(++list.begin())).get_data() , 30);

END_TEST

BEGIN_TEST(constIterator_get_data_function_test2)	

	const adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);
	list.append(70);

	adt::ListItr<int> current = list.begin();
	for(int i = 0; i < 3; ++i)
	{
		++current;
	}

	ASSERT_EQUAL(current.get_data(), 40);
	ASSERT_EQUAL(*current , 40);

END_TEST

BEGIN_TEST(constIterator_isEqual_operator_test1)	

	const adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);

	adt::ListItr<int> first = ++list.begin();
	adt::ListItr<int> second = ++list.begin();

	int result = first == second;
	
	ASSERT_EQUAL(result, 1);
	ASSERT_EQUAL(first.get_data(), 20);
	ASSERT_EQUAL(second.get_data(), 20);

END_TEST

BEGIN_TEST(constIterator_isEqual_operator_test2)	

	const adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);

	adt::ListItr<int> first = ++list.begin();
	adt::ListItr<int> second = ++(++list.begin());

	int result = first == second;
	
	ASSERT_EQUAL(result, 0);
	ASSERT_EQUAL(first.get_data(), 20);
	ASSERT_EQUAL(second.get_data(), 30);

END_TEST
*/

BEGIN_TEST(class_for_each_printer_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	printer printer;

	list.for_each(printer);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(global_for_each_printer_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	printer printer;

	for_each(list, printer);

	ASSERT_PASS();

END_TEST

BEGIN_TEST(class_for_each_multiplier_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	multiplier multiplier(2);

	list.for_each(multiplier);
	list.print();

	ASSERT_PASS();

END_TEST


BEGIN_TEST(global_for_each_multiplier_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	multiplier multiplier(2);

	for_each(list, multiplier);
	list.print();

	ASSERT_PASS();

END_TEST

BEGIN_SUITE(Slist tests)

	TEST(list_ctor_test)
	TEST(list_append_test)
	TEST(list_prepend_test)
	TEST(list_to_list_append_test)
	TEST(list_to_list_prepend_test)
	TEST(remove_front_test)
	TEST(remove_back_test)
	TEST(operator_smaller_than__test1)
	TEST(operator_smaller_than__test2)
	TEST(operator_smaller_than__test3)
	TEST(operator_is_bigger_than_test1)
	TEST(operator_is_bigger_than_test2)
	TEST(operator_is_equal_test1)
	TEST(operator_is_equal_test2)
	TEST(reverse_list_test)
	TEST(list_begin_function_test)
	TEST(list_end_function_test)
	TEST(iterator_get_data_function_test1)
	TEST(iterator_get_data_function_test2)
	TEST(iterator_set_data_function_test)
	TEST(iterator_isEqual_operator_test1)
	TEST(iterator_isEqual_operator_test2)
	TEST(class_for_each_printer_test)
	TEST(global_for_each_printer_test)
	TEST(class_for_each_multiplier_test)
	TEST(global_for_each_multiplier_test)
/*	TEST(constIterator_get_data_function_test1)
	TEST(constIterator_get_data_function_test2)
	TEST(constIterator_isEqual_operator_test1)
	TEST(constIterator_isEqual_operator_test2)
	
	
	
*/
END_SUITE