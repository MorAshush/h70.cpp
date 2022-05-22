#include "mu_test.h"

#include "slist.hpp"


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

BEGIN_TEST(remove_back_test)	

	adt::SingleLinkedList<int> list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	int data = list.remove_back();

	ASSERT_THAT(data == 60);
	ASSERT_EQUAL(list.size(), 5);

END_TEST


BEGIN_SUITE(node_default_structor_test tests)

	TEST(list_ctor_test)
	TEST(list_append_test)
	TEST(list_prepend_test)
	TEST(list_to_list_append_test)
	TEST(list_to_list_prepend_test)
	TEST(remove_back_test)



/*	
	
	TEST(list_append_with_variable)
	TEST(list_append_with_variable)
	TEST(list_prepend_with_variable)
	TEST()TEST()
*/
END_SUITE