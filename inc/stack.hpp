#ifndef INT_STACK_H
#define INT_STACK_H

#include <cstddef>

namespace adt
{
	class Stack
	{
		public:

			Stack();
			explicit Stack(size_t a_size);

			Stack(const Stack& a_stack);  //copy constructor
			Stack& operator=(const Stack& a_stack); //copy assignment operator
 
			~Stack();

			void print() const;

			void push(int a_num);

			void clear();

			int pop();

			int& top() const;

			size_t capacity() const;
			size_t size() const;
			int* stack_array() const;

			void operator+=(Stack a_stack);

			Stack& operator<<(Stack& a_stack);
			Stack& operator>>(Stack& a_stack);

		private:

			const static size_t m_DEFAULT_SIZE = 1024 * 4 * 10;
			size_t m_capacity;
			size_t m_size;
			int* m_array;
/*			FILE* m_file;*/
	};
}



#endif  //INT_STACK_H