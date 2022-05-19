#ifndef _GRAY_IMAGE_H_
#define _GRAY_IMAGE_H_

#include <cstddef>
#include <iostream>
#include <fstream>

namespace gfx
{

typedef int (*operation_func)(int a_first, int a_second);

class GrayImage
{
	public:
		GrayImage(size_t a_width, size_t a_height);
		GrayImage(size_t a_width, size_t a_height, size_t a_depth);

		GrayImage(const GrayImage& a_img); //copy constructor

		GrayImage& operator=(const GrayImage& a_img);  //copy assignment operator

		~GrayImage();

		int get_pixel(size_t a_row, size_t a_column) const;
		void set_pixel(size_t a_row, size_t a_column, size_t a_shade);
		void clear_pixel(size_t a_row, size_t a_column);

		size_t width() const;
		size_t height() const;
		size_t depth() const;
		size_t size() const;
		int* image() const;

		GrayImage operator~() const;

		int& at(size_t a_row, size_t a_column); //returns a specified pixel by refernce
		int& operator()(size_t a_row, size_t a_column); //returns a specified pixel by refernce
		int* operator[](size_t a_row); //returns a ptr to the head of specified row
		void operator&=(const GrayImage a_img);
		void operator|=(const GrayImage a_img);
		void operator^=(const GrayImage a_img);
		bool operator==(const GrayImage a_img) const;

	private:
		const static size_t DEFAULT_DEPTH = 15;
		const static size_t MAX_WIDTH = 2000;
		const static size_t MAX_HEIGHT = 2000;
		size_t m_depth;
		size_t m_width;
		size_t m_height;

		int* m_image;

};

void clear(GrayImage& a_img);

std::ostream& operator<<(std::ostream& a_os, const GrayImage& a_img);

//std::ifstream& operator>>(std::ifstream& a_os, const GrayImage& a_img);

GrayImage operator&(const GrayImage a_first, const GrayImage a_second);

GrayImage operator|(const GrayImage a_first, const GrayImage a_second);

GrayImage operator^(const GrayImage a_first, const GrayImage a_second);

bool operator!=(const GrayImage a_first, const GrayImage a_second);

void save_img(GrayImage& a_img, char* a_fileName);

GrayImage load_img(char* a_fileName);

GrayImage rotate_clockwise(GrayImage a_img);

GrayImage reduce_color(GrayImage a_img, size_t a_depth);

GrayImage scale_down_dims(GrayImage a_img, int a_scale);

void draw_line(GrayImage& a_img, size_t a_firstX, size_t a_firstY, size_t a_secondX, size_t a_secondY, int a_shade);

//void draw_circle(GrayImage& a_img, size_t a_x, size_t a_y, size_t a_radius, int a_shade);


}// namespace gfx





#endif //_GRAY_IMAGE_H_