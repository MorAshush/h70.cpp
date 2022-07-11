#include <iostream>
#include <string>


int rec_strcmp(const char* a_lhs, const char* a_rhs)
{
	if(a_lhs[0] == '\0' && (a_rhs[0] == '\0'))
	{
		return 0;
	}

	if(a_lhs[0] < a_rhs[0]) //left appears before right in lexicographical order 
	{
		return -1;
	}

	if(a_lhs[0] > a_rhs[0]) //left appears after right in lexicographical order
	{
		return 1;
	}

	return rec_strcmp(a_lhs + 1, a_rhs + 1);
}

int reverse_bits(int a_num)
{
	size_t numOfBits = sizeof(int) * 8;
	size_t numOfTimes = numOfBits / 2;

	for(size_t i = 0; i < numOfTimes; ++i)
	{
		bool lessSignificant =( a_num & 1 << i);
		bool moreSiginificant = a_num & 1 << (numOfBits - i);

		if(lessSignificant != moreSiginificant)
		{
			a_num = a_num ^ (1 << i);
			a_num = a_num ^ 1 << (numOfBits - i);
		}
	}

	return a_num;
}

int max_of_two(int a_first, int a_second)
{
	int delta = a_first - a_second;
	bool dSign = (delta >> (sizeof(int) * 8 - 1) && 1);
	
	int max = a_first - dSign * delta;

	return max;
}

void swap(int a_first, int a_second)
{
	std::cout << "a before swap: " << a_first << '\n';
	std::cout << "b before swap: " << a_second << '\n';

	size_t numOfBits = sizeof(int) * 8;

	for(size_t i = 0; i < numOfBits; ++i)
	{
		bool firstNumBit = a_first & (1 << i);
		bool SecondNumBit = a_second & (1 << i);

		if(firstNumBit != SecondNumBit)
		{
			a_first = a_first ^ (1 << i);
			a_second = a_second ^ (1 << i);
		}
	}

	std::cout << "a after swap: " << a_first << '\n';
	std::cout << "b after swap: " << a_second << "\n\n";
}

void swap_xor(int& a_first, int& a_second)
{
	std::cout << "a before swap: " << a_first << '\n';
	std::cout << "b before swap: " << a_second << '\n';

	a_first = a_first ^ a_second;
	a_second = a_first ^ a_second;
	a_first = a_first ^ a_second;

	std::cout << "a after swap: " << a_first << '\n';
	std::cout << "b after swap: " << a_second << "\n\n";
}

/*
void* malloc(size_t a_size)
{
	static int startIndex = std::ios_base::xalloc();
	std::ios stream;
	void* blockPtr = stream.pword(startIndex);
	*(static_cast<size_t*>(blockPtr)) = a_size;
	return blockPtr;
}

void free(void* a_ptr)
{
//	if(!a_ptr)
//	{
//		return;
//	}

	size_t size = *(static_cast<size_t*>(a_ptr));
	std::ios_base::xfree(a_ptr, size);
}
*/

struct Node
{
	Node* father;
	Node* left;
	Node* right;
}

int main()
{
	char firstName[] = "mor ashus";
	char lastName[] = "mor ashush";

	int r = rec_strcmp(firstName, lastName);
	std::cout << "strcmp result is : " << r << "\n\n";

	int a = 15;
	int b = 30;
	swap_xor(a, b);

	std::cout << "two ints: 15, 30\n";
	int result1 = max_of_two(15, 30);
	std::cout << "bigger int of the two: " << result1 << "\n\n";

	std::cout << "two ints: 10, 100\n";
	int result2 = max_of_two(10, 100);
	std::cout << "bigger int of the two: " << result2 << '\n';

	return 0;
}