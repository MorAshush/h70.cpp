#include <cstdio>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <fstream>

#include "gray_image.hpp"


namespace gfx
{
	GrayImage::GrayImage(size_t a_width, size_t a_height)
	:m_depth(DEFAULT_DEPTH)
	,m_width(a_width)
	,m_height(a_height)
	,m_image(static_cast<int*>(::malloc(sizeof(int) * m_width * m_height)))
	{
		assert(m_width <= MAX_WIDTH && m_height <= MAX_HEIGHT && "image size are over limits");
		assert(m_image && "matrix allocation failed");
	}


	GrayImage::GrayImage(size_t a_width, size_t a_height, size_t a_depth)
	:m_depth(a_depth)
	,m_width(a_width)
	,m_height(a_height)
	,m_image(static_cast<int*>(::malloc(sizeof(int) * m_width * m_height)))
	{
		assert(m_width <= MAX_WIDTH && m_height <= MAX_HEIGHT && "image size are over limits");
		assert(m_image && "matrix allocation failed");
	}


	GrayImage::GrayImage(const GrayImage& a_img)
	:m_depth(a_img.m_depth)
	,m_width(a_img.m_width)
	,m_height(a_img.m_height)
	,m_image(static_cast<int*>(::malloc(sizeof(int) * m_width * m_height)))
	{
		assert(m_width <= MAX_WIDTH && m_height <= MAX_HEIGHT && "image size are over limits");
		assert(m_image && "matrix allocation failed");

		for(size_t i = 0; i < m_height; ++i)
		{
			for(size_t j = 0; j < m_width; ++j)
			{
				m_image[i * m_width + j] = a_img.m_image[i * m_width + j];
			}			
		}
	}


	GrayImage& GrayImage::operator=(const GrayImage& a_other)
	{
		::free(m_image);

		m_depth = a_other.m_depth;
		m_width = a_other.m_width;
		m_height = a_other.m_height;

		m_image = static_cast<int*>(::malloc(sizeof(int) * m_width * m_height));

		assert(m_image && "array allocation failed");

		for(size_t i = 0; i < m_height; ++i)
		{
			for(size_t j = 0; j < m_width; ++j)
			{
				m_image[i * m_width + j] = a_other.m_image[i * m_width + j];
			}			
		}
		
		return *this;
	}


	GrayImage::~GrayImage()
	{
		::free(m_image);
	}


	int GrayImage::get_pixel(size_t a_row, size_t a_column)
	{
		return m_image[a_row * m_width + a_column];
	}


	void GrayImage::set_pixel(size_t a_row, size_t a_column, size_t a_shade)
	{
		assert(a_shade <= m_depth);

		m_image[a_row * m_width + a_column] = a_shade;
	}


	void GrayImage::clear_pixel(size_t a_row, size_t a_column)
	{
		m_image[a_row * m_width + a_column] = 0;
	}



	size_t GrayImage::width() const
	{
		return m_width;
	}


	size_t GrayImage::height() const
	{
		return m_height;
	}


	size_t GrayImage::depth() const
	{
		return m_depth;
	}


	size_t GrayImage::size() const
	{
		return m_height * m_width;
	}


	int* GrayImage::image() const
	{
		return m_image;
	}


	void GrayImage::clear()
	{
		for(size_t i = 0; i < m_height; ++i)
		{
			for(size_t j = 0; j < m_width; ++j)
			{
				m_image[i * m_width + j] = 15;
			}			
		}
	}


	bool operator==(const GrayImage a_first, const GrayImage a_second)
	{
		int* first = a_first.image();
		int* second = a_second.image();

		size_t width = a_first.width();
		size_t height = a_first.height();
		
		assert(first && second && "image pointer is null");

		if(width != a_second.width() || height != a_second.height() || a_first.depth() != a_second.depth())
		{
			return false;
		}

		for(size_t i = 0; i < height; ++i)
		{
			for(size_t j = 0; j < width; ++j)
			{
				if(first[i * width + j] != second[i * width + j])
				{
					return false;
				}
			}			
		}

		return true;
	}


	bool operator!=(const GrayImage a_first, const GrayImage a_second)
	{
		return !(a_first == a_second);
	}


	GrayImage& operator~(GrayImage a_img)
	{
		GrayImage& copy = a_img;
		size_t width = copy.width();
		size_t height = copy.height();
		int* imgComplement = copy.image();

		assert(imgComplement && "image pointer is null");

		for(size_t i = 0; i < height; ++i)
		{
			for(size_t j = 0; j < width; ++j)
			{
				imgComplement[i * width + j] = ~(a_img.image()[i * width + j]);
			}			
		}

		return copy;
	}

/*
	GrayImage& operator&(const GrayImage a_first, const GrayImage a_second)
	{
		return operate_on_img(a_first, a_second, '&');
	}


	GrayImage& operator|(const GrayImage a_first, const GrayImage a_second)
	{
		return operate_on_img(a_first, a_second, '|');
	}


	GrayImage& operator^(const GrayImage a_first, const GrayImage a_second)
	{
		return operate_on_img(a_first, a_second, '^');
	}


GrayImage& GrayImage::operate_on_img(const GrayImage a_first, const GrayImage a_second, char a_operant)
{
	GrayImage copy(a_first);

	int* img = copy.image();

	size_t width = copy.width();
	size_t height = copy.height();
		

	switch(a_operant)
	{
		case 38:          // operant &

			for(size_t i = 0; i < height; ++i)
			{
				for(size_t j = 0; j < width; ++j)
				{
					img[i * width + j] = a_first[i * width + j] & a_second[i * width + j];
				}			
			}

			break;

		case 94:          //operant ^

			for(size_t i = 0; i < height; ++i)
			{
				for(size_t j = 0; j < width; ++j)
				{
					copy[i * width + j] = a_first[i * width + j] ^ a_second[i * width + j];
				}			
			}

			break;

		case 124:         //operant |

			for(size_t i = 0; i < height; ++i)
			{
				for(size_t j = 0; j < width; ++j)
				{
					copy[i * width + j] = a_first[i * width + j] | a_second[i * width + j];
				}			
			}

			break;
	}

	return copy;
}
*/

void GrayImage::save_img(char* a_fileName)
{
	FILE* filePtr = fopen("my_first_gfx.pbm", "w");

	assert(filePtr && "File couldn't be opened");

	fprintf(filePtr, "P2\n%ld %ld\n%ld\n", m_width, m_height, m_depth);

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			fprintf(filePtr,"%d", m_image[i * m_width + j]);

			if(j < m_width - 1)
			{
				fprintf(filePtr, " ");
			}	
		}			
	}
	fclose(filePtr);
}


void GrayImage::read_img(char* a_fileName)
{
	FILE* filePtr = fopen("my_first_gfx.pbm", "r");
	char buffer[MAX_WIDTH];

	assert(filePtr && "file couldn't be opened");
	
	for(int i = 0; i < 3; ++i)
	{
		fgets(buffer, 5, filePtr);
		printf("%s\n", buffer);
	}	

	fgets(buffer, m_width, filePtr);

	while(!feof(filePtr))
	{
		printf("%s\n", buffer);
		fgets(buffer, m_width, filePtr);
	}

	fclose(filePtr);	
}


}//namespace gfx
