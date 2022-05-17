#ifndef _GRAY_IMAGE_H_
#define _GRAY_IMAGE_H_

#include <cstddef>

namespace gfx
{
	class GrayImage
	{
		public:
			GrayImage(size_t a_width, size_t a_height);
			GrayImage(size_t a_width, size_t a_height, size_t a_depth);

			GrayImage(const GrayImage& a_img); //copy constructor

			GrayImage& operator=(const GrayImage& a_img);  //copy assignment operator

			~GrayImage();

			int get_pixel(size_t a_row, size_t a_column);
			void set_pixel(size_t a_row, size_t a_column, size_t a_shade);
			void clear_pixel(size_t a_row, size_t a_column);

			size_t width() const;
			size_t height() const;
			size_t depth() const;
			size_t size() const;
			int* image() const;

			void clear();

			void operator&=(const GrayImage a_img);
			void operator|=(const GrayImage a_img);
			void operator^=(const GrayImage a_img);

			void save_img(char* a_fileName);
			void read_img(char* a_fileName);

		private:
			GrayImage& operate_on_img(const GrayImage a_first, const GrayImage a_second, char a_operant);

		private:
			const static size_t DEFAULT_DEPTH = 15;
			const static size_t MAX_WIDTH = 600;
			const static size_t MAX_HEIGHT = 500;
			size_t m_depth;
			size_t m_width;
			size_t m_height;

			int* m_image;

	};


GrayImage& operator~(const GrayImage a_img);
GrayImage& operator&(const GrayImage a_first, const GrayImage a_second);
GrayImage& operator|(const GrayImage a_first, const GrayImage a_second);
GrayImage& operator^(const GrayImage a_first, const GrayImage a_second);

bool operator==(const GrayImage a_first, const GrayImage a_second);
bool operator!=(const GrayImage a_first, const GrayImage a_second);



}// namespace gfx




















#endif //_GRAY_IMAGE_H_