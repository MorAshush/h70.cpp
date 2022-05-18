#include <cstdio>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>


#include "gray_image.hpp"


namespace gfx
{

namespace implementation_details
{
static double calc_chunk_avg(GrayImage a_img, size_t a_row, size_t a_column, int a_scale)
{
//	size_t rowSkip = 
//	size_t columnSkip =
	double sum = 0;
	for(size_t i = 0; i < a_row + a_scale; ++i)
	{
		for(size_t j = 0; j < a_column + a_scale; ++j)
		{
			sum += a_img.get_pixel(i, j);
		}
	}

	return sum / (a_scale * a_scale);
}


static double calc_incline(size_t a_firstX, size_t a_firstY, size_t a_secondX, size_t a_secondY)
{
	double incline = (a_secondY - a_firstY) / (a_secondX - a_firstX);

	return incline;
}
}//namespace implementation_details



GrayImage::GrayImage(size_t a_width, size_t a_height)
:m_depth(DEFAULT_DEPTH)
,m_width(a_width)
,m_height(a_height)
{
	assert(m_width <= MAX_WIDTH && m_height <= MAX_HEIGHT && "image size are over limits");

	m_image = new int[m_width * m_height];
	assert(m_image && "matrix allocation failed");
}


GrayImage::GrayImage(size_t a_width, size_t a_height, size_t a_depth)
:m_depth(a_depth)
,m_width(a_width)
,m_height(a_height)
{
	assert(m_width <= MAX_WIDTH && m_height <= MAX_HEIGHT && "image size are over limits");

	m_image = new int[m_width * m_height];
	assert(m_image && "matrix allocation failed");
}


GrayImage::GrayImage(const GrayImage& a_img)
:m_depth(a_img.m_depth)
,m_width(a_img.m_width)
,m_height(a_img.m_height)
,m_image(new int[m_width * m_height])
{
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
	if(&a_other == this)
	{
		return *this;
	}

	delete[] m_image;

	m_depth = a_other.m_depth;
	m_width = a_other.m_width;
	m_height = a_other.m_height;

	m_image = new int[m_width * m_height];

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
	delete[] m_image;
}


int& GrayImage::at(size_t a_row, size_t a_column)
{
	assert(a_row < m_height && a_column < m_width && "input is not in img size");

	return m_image[a_row * m_width + a_column];
}


int GrayImage::get_pixel(size_t a_row, size_t a_column) const
{
	assert(a_row < m_height && a_column < m_width && "input is not in img size");

	return m_image[a_row * m_width + a_column];
}


void GrayImage::set_pixel(size_t a_row, size_t a_column, size_t a_shade)
{
	assert(a_row < m_height && a_column < m_width && a_shade <= m_depth && "input is not in img size");

	m_image[a_row * m_width + a_column] = a_shade;
}


void GrayImage::clear_pixel(size_t a_row, size_t a_column)
{
	assert(a_row <= m_height && a_column <= m_width && "input is not in img size");
	m_image[a_row * m_width + a_column] = m_depth;
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


void clear(GrayImage& a_img)
{
	for(size_t i = 0; i < a_img.height() ; ++i)
	{
		for(size_t j = 0; j < a_img.width() ; ++j)
		{
			a_img.clear_pixel(i, j);
		}			
	}
}


GrayImage GrayImage::operator~() const
{
	GrayImage copy(*this);

	int* imgComplement = copy.image();

	assert(imgComplement && "image pointer is null");

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			imgComplement[i * m_width + j] = m_depth - this->get_pixel(i, j);
		}			
	}

	return copy;
}


int& GrayImage::operator()(size_t a_row, size_t a_column)
{
	assert(a_row <= m_height && a_column <= m_width && "input is not in img size");
	return m_image[a_row * m_width + a_column];
}


int* GrayImage::operator[](size_t a_row)
{
	assert(a_row <= m_height && "input is not in img size");
	return &m_image[a_row * m_width];
}


void GrayImage::operator&=(const GrayImage a_img)
{
	assert(m_width == a_img.m_width && m_height == a_img.m_height && "images are not equal to operate & on");

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			m_image[i * m_width + j] &= a_img.m_image[i * m_width + j];
		}			
	}
}


void GrayImage::operator|=(const GrayImage a_img)
{
	assert(m_width == a_img.m_width && m_height == a_img.m_height && m_depth == a_img.m_depth && "images are not equal to operate & on");

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			m_image[i * m_width + j] |= a_img.m_image[i * m_width + j];
		}			
	}
}


void GrayImage::operator^=(const GrayImage a_img)
{
	assert(m_width == a_img.m_width && m_height == a_img.m_height && m_depth == a_img.m_depth && "images are not equal to operate & on");

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			m_image[i * m_width + j] ^= a_img.m_image[i * m_width + j];
		}			
	}
}


bool GrayImage::operator==(const GrayImage a_img) const

{
	if(m_width != a_img.width() || m_height != a_img.height() || m_depth != a_img.depth())
	{
		return false;
	}

	for(size_t i = 0; i < m_height; ++i)
	{
		for(size_t j = 0; j < m_width; ++j)
		{
			if(this->get_pixel(i, j) != a_img.get_pixel(i, j))
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


GrayImage operator&(const GrayImage a_first, const GrayImage a_second)
{
	GrayImage copy = a_first;

	copy &= a_second;

	return copy; 
}


GrayImage operator|(const GrayImage a_first, const GrayImage a_second)
{
	GrayImage copy = a_first;

	copy |= a_second;
	
	return copy; 
}


GrayImage operator^(const GrayImage a_first, const GrayImage a_second)
{
	GrayImage copy = a_first;

	copy ^= a_second;
	
	return copy; 
}


void save_img(GrayImage& a_img, char* a_fileName)
{
	FILE* filePtr = fopen(a_fileName, "w");
	assert(filePtr && "File couldn't be opened");

	size_t width = (a_img.width());
	size_t height = (a_img.height());
	size_t depth = (a_img.depth());

	fprintf(filePtr, "P2\n%ld %ld\n%ld\n", width, height, depth);

	for(size_t i = 0; i < height; ++i)
	{
		for(size_t j = 0; j < width; ++j)
		{
			fprintf(filePtr,"%d ", a_img.image()[i * width + j]);
		}

		fprintf(filePtr,"\n");			
	}

	fclose(filePtr);
}


std::ostream& operator<<(std::ostream& a_os, const GrayImage& a_img)
{
	a_os << "P2\n" << a_img.width() << ' ' << a_img.height() << '\n';

	for(size_t i = 0; i < a_img.height(); ++i)
	{
		for(size_t j = 0; j < a_img.width(); ++j)
		{
			a_os << a_img.get_pixel(i, j) << ' ';
		}

		a_os << '\n';			
	}

	return a_os;
}



GrayImage load_img(char* a_fileName)
{
	FILE* filePtr = fopen(a_fileName, "r");
	assert(filePtr && "file couldn't be opened");

	int width;
	int height;
	int depth;
	int pixel;
	
	fseek(filePtr, 2, SEEK_SET);
	fscanf(filePtr, "%d %d %d", &width, &height, &depth);

	GrayImage loadedImg(width, height, depth);

	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			fscanf(filePtr,"%d", &pixel);
			loadedImg.set_pixel(i, j, pixel);
		}
	}	
	
	fclose(filePtr);

	return loadedImg;	
}

GrayImage rotate_clockwise(GrayImage a_img)
{
	GrayImage copy (a_img.height(), a_img.width(), a_img.depth());

	for(size_t i = 0; i < copy.height(); ++i)
	{
		for(size_t j = 0; j < copy.width(); ++j)
		{
			copy(i, j) = a_img(a_img.height() - 1 - j, i);
		}
	}

	return copy;	
}



GrayImage reduce_color(GrayImage a_img, size_t a_depth)
{
	GrayImage copy(a_img);
	size_t reduceRatio = copy.depth() / a_depth;
	assert(reduceRatio > 1 && "reduced depth must be smaller than original");

	for(size_t i = 0; i < copy.height(); ++i)
	{
		for(size_t j = 0; j < copy.width(); ++j)
		{
			copy(i, j) /= reduceRatio;
		}
	}	

	return copy;
}


GrayImage scale_down_dims(GrayImage a_img, int a_scale)
{
	GrayImage copy(a_img.width()/a_scale, a_img.height()/a_scale, a_img.depth());

//	int chunkSize = copy.size() / a_img.size();

	assert(a_scale > 1 && "scale value is less than 1");

	size_t r = 0;
	for(size_t i = 0; i < a_img.height(); i += a_scale)
	{
		size_t c = 0;

		for(size_t j = 0; j < a_img.width(); j += a_scale)
		{
			copy(r, c) =  implementation_details::calc_chunk_avg(a_img, i, j, a_scale);
			++c;
		}

		++r;
	}	

	return copy;
}


void draw_line(GrayImage& a_img, size_t a_firstX, size_t a_firstY, size_t a_secondX, size_t a_secondY, int a_shade)
{
	double a = implementation_details::calc_incline(a_firstX, a_firstY, a_secondX, a_secondY);
	double b = a * a_firstX - a_firstY;
	//y = a * x + b

	for(size_t i = 0; i < a_img.height(); ++i)
	{
		for(size_t j = 0; j < a_img.width(); ++j)
		{
			double y = a * j + b;
			if(static_cast<size_t>(y) == i )
			{
				a_img(i, j) = a_shade;
			}
		}
	}	
}



}//namespace gfx
