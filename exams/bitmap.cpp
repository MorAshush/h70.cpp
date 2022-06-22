#include <fstream>
#include <cstddef>
#include <math.h>

struct Holder
{
	bool m_have;
	int m_value;
};

Holder find_missing_value(const char* a_fileName)
{
	size_t arrSize = pow(2, 32) / 8;
	char bitMap[arrSize];

	std::ifstream fin;
    fin.open(a_fileName);
    assert(fin && "file couldn't be opened");

    int num;
	read_next_num(fin, num);

	while(fin)
	{
		size_t index = num / 8;
		size_t offset = num % 8 - 1;

		set_bit(&bitMap[index], offset);
		read_next_num(fin, num);
	}

	return get_missing_value(bitMap, arrSize);
}


void set_bit(char* a_element, size_t a_offset)
{
	char mask = 1 << a_offset;
	*a_element = *a_element | mask;
}

size_t find_clear_bit(char a_element)
{
	for(size_t i = 1; i < sizeof(char) * 8; ++i)
	{
		char mask = 1 << i;
		char result = a_element | mask;
		if(!result)
		{
			return i;
		}
	}
}

int calc_actual_value(size_t a_index, size_t a_offset)
{
	return a_index * 8 + a_offset;
}

Holder get_missing_value(const char* a_bitMap, size_t a_size)
{
	Holder h = {0, 0};

	for (size_t i = 0; i < a_size; ++i)
	{
		if(a_bitMap[i] < 255)
		{
			size_t offset = find_clear_bit(a_bitMap[i]);
			int value = calc_actual_value(i, offset);
			h = {1, value};
			return h;
		}
	}

	return h;
}
