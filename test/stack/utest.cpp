#include "mu_test.h"

#include "stack.hpp"

//constructor functions

BEGIN_TEST(stack_constructor_test1)	

	adt::Stack s(100);
	size_t size = s.get_size();

	ASSERT_THAT(size == 100);
	ASSERT_THAT(s.get_num_of_items() == 0);
	ASSERT_THAT(s.get_stack_array());

END_TEST

BEGIN_TEST(stack_constructor_test2)	

	adt::Stack s;
	size_t size = s.get_size();

	ASSERT_THAT(size == 16);
	ASSERT_THAT(s.get_num_of_items() == 0);
	ASSERT_THAT(s.get_stack_array());

END_TEST

//class function push

BEGIN_TEST(stack_push_when_size_is_zero)	

	adt::Stack s(0);
	s.push(2);
	
	ASSERT_PASS();

END_TEST

BEGIN_TEST(stack_push_when_able_to_push)

	adt::Stack s(5);
	s.push(2);

	size_t size = s.get_size();

	ASSERT_THAT(size == 5);
	ASSERT_THAT(s.get_num_of_items() == 1);	


END_TEST

BEGIN_TEST(stack_push_when_overflow)
	
	adt::Stack s(2);
	s.push(2);
	s.push(9);
	s.push(15);

	size_t size = s.get_size();

	printf("%ld\n", size);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(stack_push_multiple_pushes)

	adt::Stack s(10);
	s.push(2);
	s.push(9);
	s.push(15);
	s.push(2);
	s.push(9);
	s.push(15);

	size_t size = s.get_size();

	ASSERT_THAT(size == 10);
	ASSERT_THAT(s.get_num_of_items() == 6);	

END_TEST

//class function pop

BEGIN_TEST(stack_pop_when_empty_stack)	

	adt::Stack s(10);
	
	s.pop();

	ASSERT_PASS();

END_TEST

BEGIN_TEST(stack_pop_when_stack_is_not_empty)

	adt::Stack s(10);
	s.push(2);
	s.push(9);

	int popped = s.pop();
	size_t size = s.get_size();

	ASSERT_THAT(size == 10);
	ASSERT_THAT(s.get_num_of_items() == 1);	
	ASSERT_EQUAL(popped, 9);

END_TEST

BEGIN_TEST(stack_pop_multiple_pops)	

	adt::Stack s(10);
	s.push(2);
	s.push(9);
	s.push(15);
	s.push(2);
	s.push(9);
	s.push(15);

	int popped1 = s.pop();
	int popped2 = s.pop();
	int popped3 = s.pop();

	size_t size = s.get_size();

	ASSERT_THAT(size == 10);
	ASSERT_THAT(s.get_num_of_items() == 3);	
	ASSERT_EQUAL(popped1, 15);
	ASSERT_EQUAL(popped2, 9);
	ASSERT_EQUAL(popped3, 2);

END_TEST

//class function clear

BEGIN_TEST(stack_clear_a_full_stack)

	adt::Stack s(10);
	s.push(2);
	s.push(9);
	s.push(15);

	s.clear();

	ASSERT_THAT(s.get_size() == 10);
	ASSERT_THAT(s.get_num_of_items() == 0);	

END_TEST

//class function top

BEGIN_TEST(stack_top_when_underflow)

	adt::Stack s(20);

	s.top();

	ASSERT_PASS();	

END_TEST

BEGIN_TEST(stack_top_when_stack_is_not_empty)	

	adt::Stack s(20);
	s.push(12);
	s.push(52);
	s.push(34);

	int top = s.top();

	ASSERT_THAT(s.get_size() == 20);
	ASSERT_THAT(s.get_num_of_items() == 3);	
	ASSERT_EQUAL(top, 34);	

END_TEST

//class function get stack array

BEGIN_TEST(stack_get_array_when_stack_is_not_empty)

	adt::Stack s(20);
	s.push(12);
	s.push(52);
	s.push(34);

	int* array = s.get_stack_array();

	ASSERT_THAT(s.get_size() == 20);
	ASSERT_THAT(s.get_num_of_items() == 3);	
	ASSERT_THAT(array);
	ASSERT_THAT(array[0] == 12);

END_TEST
/*
BEGIN_TEST(stack_get_array_when_underflow)	


END_TEST
*/

//class function operator +=

BEGIN_TEST(stack_operator_add_when_both_stack_arent_empty)

	adt::Stack first(20);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);

	first += second;
	int* array = first.get_stack_array();

	ASSERT_THAT(first.get_size() == 20);
	ASSERT_THAT(first.get_num_of_items() == 6);	
	ASSERT_THAT(second.get_num_of_items() == 3);	
	ASSERT_THAT(array[3] == 20);	

END_TEST

BEGIN_TEST(stack_operator_add_when_both_stack_are_empty)

	adt::Stack first(20);
	adt::Stack second(10);

	first += second;

	ASSERT_THAT(first.get_size() == 20);
	ASSERT_THAT(first.get_num_of_items() == 0);	

END_TEST

BEGIN_TEST(stack_operator_add_when_one_stack_is_empty)	

	adt::Stack first(20);
	adt::Stack second(10);

	second.push(15);
	second.push(26);
	second.push(38);

	first += second;

	ASSERT_THAT(first.get_size() == 20);
	ASSERT_THAT(first.get_num_of_items() == 3);
	ASSERT_THAT(second.get_num_of_items() == 3);	

END_TEST

BEGIN_TEST(stack_operator_add_when_one_stack_is_empty2)	

	adt::Stack first(20);
	adt::Stack second(10);

	first.push(15);
	first.push(26);
	first.push(38);

	first += second;

	ASSERT_THAT(first.get_size() == 20);
	ASSERT_THAT(first.get_num_of_items() == 3);
	ASSERT_THAT(second.get_num_of_items() == 0);
END_TEST


BEGIN_TEST(stack_operator_add_when_overflow)

	adt::Stack first(5);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);

	first += second;

	ASSERT_PASS();		

END_TEST

//class function operator << (passing a stack to self)

BEGIN_TEST(class_operator_move_a_stack_into_self_1)

	adt::Stack first(7);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);
	adt::Stack& secondR = second;
	first << secondR;

	ASSERT_THAT(first.get_size() == 7);
	ASSERT_THAT(first.get_num_of_items() == 6);
	ASSERT_THAT(second.get_num_of_items() == 0);

END_TEST

BEGIN_TEST(class_operator_move_a_stack_into_self_2)	

	adt::Stack first(7);
	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);

	first << second;

	ASSERT_THAT(first.get_size() == 7);
	ASSERT_THAT(first.get_num_of_items() == 3);
	ASSERT_THAT(second.get_num_of_items() == 0);

END_TEST

BEGIN_TEST(class_operator_move_a_stack_into_self_3)

	adt::Stack first(7);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	first << second;

	ASSERT_THAT(first.get_size() == 7);
	ASSERT_THAT(first.get_num_of_items() == 3);
	ASSERT_THAT(second.get_num_of_items() == 0);

END_TEST

//class function operator >> (moving self into other stack)

BEGIN_TEST(class_operator_move_self_into_stack_1)	

	adt::Stack first(7);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);

	first >> second;

	ASSERT_THAT(second.get_size() == 10);
	ASSERT_THAT(second.get_num_of_items() == 6);
	ASSERT_THAT(first.get_num_of_items() == 0);

END_TEST

BEGIN_TEST(class_operator_move_self_into_stack_2)

	adt::Stack first(7);
	adt::Stack second(10);

	second.push(20);
	second.push(30);
	second.push(40);

	first >> second;

	ASSERT_THAT(second.get_size() == 10);
	ASSERT_THAT(second.get_num_of_items() == 3);
	ASSERT_THAT(first.get_num_of_items() == 0);	

END_TEST

BEGIN_TEST(class_operator_move_self_into_stack_3)

	adt::Stack first(7);

	first.push(12);
	first.push(52);
	first.push(34);

	adt::Stack second(10);

	first >> second;

	ASSERT_THAT(second.get_size() == 10);
	ASSERT_THAT(second.get_num_of_items() == 3);
	ASSERT_THAT(first.get_num_of_items() == 0);	


END_TEST


BEGIN_TEST(print_stack_when_empty)	

	adt::Stack first(7);

	first.print();

	ASSERT_PASS();


END_TEST

BEGIN_TEST(print_stack_when_not_empty)

	adt::Stack first(7);

	first.push(12);
	first.push(52);
	first.push(34);

	first.print();

	ASSERT_PASS();	

END_TEST


BEGIN_SUITE(stamstam)

	TEST(stack_constructor_test1)
	TEST(stack_constructor_test2)

	TEST(stack_push_when_size_is_zero)
	TEST(stack_push_when_able_to_push)
	TEST(stack_push_when_overflow)
	TEST(stack_push_multiple_pushes)

	TEST(stack_pop_when_empty_stack)
	TEST(stack_pop_when_stack_is_not_empty)
	TEST(stack_pop_multiple_pops)

	TEST(stack_clear_a_full_stack)

	TEST(stack_top_when_underflow)
	TEST(stack_top_when_stack_is_not_empty)

	TEST(stack_get_array_when_stack_is_not_empty)

	TEST(stack_operator_add_when_both_stack_arent_empty)
	TEST(stack_operator_add_when_both_stack_are_empty)
	TEST(stack_operator_add_when_one_stack_is_empty)
	TEST(stack_operator_add_when_one_stack_is_empty2)
	TEST(stack_operator_add_when_overflow)

	TEST(class_operator_move_a_stack_into_self_1)
	TEST(class_operator_move_a_stack_into_self_2)
	TEST(class_operator_move_a_stack_into_self_3)

	TEST(class_operator_move_self_into_stack_1)
	TEST(class_operator_move_self_into_stack_2)
	TEST(class_operator_move_self_into_stack_3)

	TEST(print_stack_when_empty)
	TEST(print_stack_when_not_empty)

/*	
	
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
*/
END_SUITE