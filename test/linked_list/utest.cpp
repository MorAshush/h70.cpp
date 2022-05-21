#include "mu_test.h"

#include "slist.hpp"

using namespace adt;

BEGIN_TEST(node_default_constructor_test)	

	adt::Node<int> newNode(0, 0);

	ASSERT_THAT(newNode.next() == 0);
	ASSERT_THAT(newNode.data() == 0);

END_TEST

BEGIN_TEST(node_constructor_test)	

	adt::Node<int> sentinal(0, 0);
	adt::Node<int> newNode(10, &sentinal);

	ASSERT_EQUAL(newNode.data(), 10);
	ASSERT_THAT(newNode.next() == &sentinal);

END_TEST

BEGIN_TEST(node_copy_constructor_test)	

	adt::Node<int> sentinal(0, 0);
	adt::Node<int> newNode(10, &sentinal);
	adt::Node<int> copy(newNode);

	ASSERT_EQUAL(copy.data(), newNode.data());
	ASSERT_THAT(copy.next() == &sentinal);

END_TEST

BEGIN_TEST(class_function_next_test)

	adt::Node<int> sentinal(0, 0);	

	adt::Node<int> first(10, &sentinal);

	adt::Node<int> second(20, &first);

	ASSERT_THAT(second.next() == &first);
	ASSERT_THAT(first.next() == &sentinal);
	ASSERT_EQUAL(second.next()->data(), 10);

END_TEST

BEGIN_TEST(class_operator_assignment_test)

	adt::Node<int> sentinal(0, 0);	

	adt::Node<int> first(10, &sentinal);

	adt::Node<int> second = first;;

	ASSERT_THAT(second.next() == first.next());
	ASSERT_THAT(second.next()->next() == 0);
	ASSERT_EQUAL(second.data(), 10);

END_TEST

BEGIN_TEST(list_constructor_test)

	adt::SingleLinkedList<int> list;

	ASSERT_THAT(list.size() == 0);

END_TEST

BEGIN_TEST(list_append_with_variable)

	adt::SingleLinkedList<int> list;

	list.append(10);
	list.append(20);
	list.append(30);

	printf("size is : %ld\n", list.size());
	printf("front is : %d\n", list.front()->data());
	printf("back is : %d\n", list.back()->data());

	ASSERT_THAT(list.size() == 3);
	ASSERT_THAT(list.front()->data() == 10);
	ASSERT_THAT(list.back()->data() == 30);

END_TEST

BEGIN_TEST(list_prepend_with_variable)

	adt::SingleLinkedList<int> list;

	list.prepend(10);
	list.prepend(20);
	list.prepend(30);

	printf("size is : %ld\n", list.size());
	printf("front is : %d\n", list.front()->data());
	printf("back is : %d\n", list.back()->data());

	ASSERT_THAT(list.size() == 3);
	ASSERT_THAT(list.front()->data() == 30);
	ASSERT_THAT(list.back()->data() == 10);

END_TEST
/*
BEGIN_TEST(get_front_test)

END_TEST

BEGIN_TEST(get_back_test)

END_TEST
*/

BEGIN_SUITE(node_default_structor_test tests)

	TEST(node_default_constructor_test)
	TEST(node_constructor_test)
	TEST(node_copy_constructor_test)
	TEST(class_function_next_test)
	TEST(class_operator_assignment_test)
	TEST(list_constructor_test)
	TEST(list_append_with_variable)
	TEST(list_append_with_variable)
	TEST(list_prepend_with_variable)
//	TEST()TEST()

END_SUITE