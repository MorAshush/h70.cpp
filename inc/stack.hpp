#ifndef INT_STACK_H
#define INT_STACK_H

#include <cstddef>

namespace adt
{
	class Stack
	{
		public:

			Stack(size_t a_size);
			Stack();

			void print() const;

			void push(int a_num);

			void clear();

			int pop();

			int& top() const;

			size_t get_size() const;
			size_t get_num_of_items() const;
			int* get_stack_array() const;

			void operator+=(const Stack a_stack);

			void operator<<(Stack& a_stack);
			void operator>>(Stack& a_stack);

		private:

			int* m_array;
			size_t m_size;
			size_t m_num_of_items;
	};
}



#endif  //INT_STACK_H