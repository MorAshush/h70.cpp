#include "mu_test.h"

#include "gray_image.hpp"

//constructors tests:

BEGIN_TEST(constructor1_test_size_in_limits_with_depth)	

	gfx::GrayImage img(200, 100, 20);

	ASSERT_THAT(img.depth() == 20);
	ASSERT_THAT(img.width() == 200);
	ASSERT_THAT(img.height() == 100);
	ASSERT_THAT(img.image());	

END_TEST

BEGIN_TEST(constructor1_test_size_not_in_limits)	

	gfx::GrayImage img(1000, 700, 100);
	
	ASSERT_PASS();

END_TEST

BEGIN_TEST(constructor2_test_size_in_limits_default_depth)	

	gfx::GrayImage img(200, 100);

	ASSERT_THAT(img.depth() == 15);
	ASSERT_THAT(img.width() == 200);
	ASSERT_THAT(img.height() == 100);
	ASSERT_THAT(img.image());		

END_TEST

BEGIN_TEST(constructor2_test_size_not_in_limits_default_depth)	

	gfx::GrayImage img(1000, 100);

	ASSERT_PASS();	

END_TEST

BEGIN_TEST(copy_constructor_test)	

	gfx::GrayImage img(200, 100);
	gfx::GrayImage copy(img);

	ASSERT_EQUAL(copy.depth(), img.depth());
	ASSERT_EQUAL(copy.width(), img.width());
	ASSERT_EQUAL(copy.height(), img.height());
	ASSERT_THAT(copy.image() != img.image());	

END_TEST

BEGIN_TEST(copy_operator_assignment_test_with_self_assignment)	

	gfx::GrayImage img(200, 100);
	img = img;

	ASSERT_THAT(img.image() == img.image());	
	
END_TEST

BEGIN_TEST(copy_operator_assignment_test_not_self_assignment)

	gfx::GrayImage img(200, 100);
	gfx::GrayImage copy(100, 40);
	copy = img;

	ASSERT_EQUAL(copy.depth(), img.depth());
	ASSERT_EQUAL(copy.width(), img.width());
	ASSERT_EQUAL(copy.height(), img.height());
	ASSERT_THAT(copy.image() != img.image());	

END_TEST


//get_pixel tests:

BEGIN_TEST(class_function_get_pixel_in_array)	

	gfx::GrayImage img(200, 100);

	img.set_pixel(10, 20, 15);
	int pixel = img.get_pixel(10, 20);

	ASSERT_EQUAL(pixel, 15);	

END_TEST

//set_pixel tests:

BEGIN_TEST(class_function_set_pixel_in_array)	

	gfx::GrayImage img(50, 20);

	for (size_t i = 0; i < 15; ++i)
	{
		img.set_pixel(i, i, i);

		int pixel = img.get_pixel(i, i);

		ASSERT_EQUAL(pixel, img.get_pixel(i, i));
	}

END_TEST

//clear_pixel tests:

BEGIN_TEST(class_function_clear_pixel_when_in_array)	

	gfx::GrayImage img(50, 20);

	for (size_t i = 0; i < 15; ++i)
	{
		img.set_pixel(i, i, i);

		img.clear_pixel(i, i);

		ASSERT_EQUAL(15, img.get_pixel(i, i));
	}	

END_TEST

//width, height, depth and get image ptr tests

BEGIN_TEST(class_function_to_get_width_test)	

	gfx::GrayImage img(50, 20);

	ASSERT_EQUAL(50, img.width());
	ASSERT_EQUAL(1000, img.size());
	ASSERT_THAT(img.image());
		

END_TEST

BEGIN_TEST(class_function_to_get_height_test)	

	gfx::GrayImage img(50, 20);

	ASSERT_EQUAL(20, img.height());
	ASSERT_EQUAL(1000, img.size());
	ASSERT_THAT(img.image());

END_TEST

BEGIN_TEST(class_function_to_get_depth_test1)	

	gfx::GrayImage img(50, 20);	

	ASSERT_EQUAL(15, img.depth());
	ASSERT_EQUAL(1000, img.size());	
	ASSERT_THAT(img.image());	

END_TEST

BEGIN_TEST(class_function_to_get_depth_test2)	

	gfx::GrayImage img(50, 20, 30);	

	ASSERT_EQUAL(30, img.depth());
	ASSERT_EQUAL(1000, img.size());
	ASSERT_THAT(img.image());	

END_TEST

//complement operator class function

BEGIN_TEST(class_function_operator_complement_test)	

	gfx::GrayImage img(50, 50, 50);

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}	

	gfx::GrayImage negative = ~img;

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			ASSERT_EQUAL(negative.get_pixel(i, j), 50 - img.get_pixel(i, j));
		}			
	}	

END_TEST

//class function at:

BEGIN_TEST(class_function_at_test)	

	gfx::GrayImage img(50, 50, 50);

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}		

	int& pixel = img.at(10, 15);

	ASSERT_EQUAL(pixel, 15);

	pixel = 0;
	
	ASSERT_EQUAL(pixel, 0);

END_TEST

//class operator function (): 

BEGIN_TEST(class_operator_function_round_brackets)	
	
	gfx::GrayImage img(50, 50, 50);

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}

	int& pixel = img(10, 15);

	ASSERT_EQUAL(pixel, 15);

	pixel = 0;
	
	ASSERT_EQUAL(pixel, 0);		
	
END_TEST

//class operator function []: 

BEGIN_TEST(class_operator_function_square_brackets)	

	gfx::GrayImage img(50, 50, 50);

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}

	int& pixel = img[10][15];

	ASSERT_EQUAL(pixel, 15);

	pixel = 0;		

END_TEST


//global function clear:

BEGIN_TEST(global_function_clear_img_test)	

	gfx::GrayImage img(50, 50, 50);

	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}	

	clear(img);

	for (size_t i = 0; i < 20; ++i)
	{
		ASSERT_THAT(50 == img.get_pixel(i, i));
	}	

END_TEST

//global function save_img:
/*
void line(gfx::GrayImage& a_img)
{
	for(size_t i = 0; i < a_img.width() - 3; ++i)
	{
		a_img(i +3, i) = 0;
	}
}
*/
BEGIN_TEST(save_img_test)	

	gfx::GrayImage img(500, 500, 100);
	for(size_t i = 0; i < 500; ++i)
	{
		for(size_t j = 0; j < 500; ++j)
		{
			img.set_pixel(i, j, j % 100);
		}			
	}		

/*	line(img);*/

	char fileName[] = "my_first_gfx.pgm";
	save_img(img, fileName);

	ASSERT_PASS();

END_TEST


//global function load_img:

BEGIN_TEST(load_img_function_test)
	
	char fileName1[] = "cat.pgm";
	char fileName2[] = "tiger.pgm";
	char fileName3[] = "lenna.pgm";

	gfx::GrayImage img1 = gfx::load_img(fileName1);
	gfx::GrayImage img2 = gfx::load_img(fileName2);
	gfx::GrayImage img3 = gfx::load_img(fileName3);

	char copyTo1[] = "cat_copy_test.pgm";
	char copyTo2[] = "tiger_copy_test.pgm";
	char copyTo3[] = "lenna_copy_test.pgm";
	
	save_img(img1, copyTo1);
	save_img(img2, copyTo2);
	save_img(img3, copyTo3);	

	ASSERT_PASS();	

END_TEST

//global function rotate_clockwise:

BEGIN_TEST(rotate_img_ninty_deg_clockwise_test)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);
	gfx::GrayImage rotated = rotate_clockwise(img);

	char copyTo[] = "tiger_rotate_test.pgm";
	save_img(rotated, copyTo);

	ASSERT_PASS();	

END_TEST

//global function reduce_color:

BEGIN_TEST(reduce_color_test)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);

	gfx::GrayImage reduced = reduce_color(img, 100);
	char copy[] = "reduced_test.pgm";

	save_img(reduced, copy);

	ASSERT_PASS();	

END_TEST

//global function scale_down_dims:

BEGIN_TEST(scale_down_dims_test)

	gfx::GrayImage img(50, 50, 50);
	for(size_t i = 0; i < 50; ++i)
	{
		for(size_t j = 0; j < 50; ++j)
		{
			img.set_pixel(i, j, j);
		}			
	}	

	gfx::GrayImage scaled = scale_down_dims(img, 3);
	char copy[] = "scaled_down_test.pgm";

	save_img(scaled, copy);

	ASSERT_PASS();	

END_TEST

//draw_line test:

BEGIN_TEST(draw_line_test1)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);

	draw_line(img, 0, 0, 200, 300, 0);
	char copy[] = "draw_line1_test.pgm";

	save_img(img, copy);	

	ASSERT_PASS();	

END_TEST

BEGIN_TEST(draw_line_test2)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);

	draw_line(img, 300, 1500, 700, 200, 0);
	char copy[] = "draw_line2_test.pgm";

	save_img(img, copy);	

	ASSERT_PASS();	

END_TEST

//class operator function &=:

BEGIN_TEST(and_operator_on_self)	

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);
	img &= img;
	
	char copy[] = "and_equal_operator.pgm";
	save_img(img, copy);	

	ASSERT_PASS();	

END_TEST

BEGIN_TEST(and_operator_not_on_self)

	gfx::GrayImage img1(1200, 1200, 255);
	for(size_t i = 0; i < 1200; ++i)
	{
		for(size_t j = 0; j < 1200; ++j)
		{
			img1.set_pixel(i, j, j % 200);
		}			
	}	

	char fileName2[] = "cat.pgm";
	gfx::GrayImage img2 = gfx::load_img(fileName2);

	img1 &= img2;
	
	char copy[] = "and_equal_operator2.pgm";
	save_img(img1, copy);	

	ASSERT_PASS();	

END_TEST


//class operator function |=:

BEGIN_TEST(or_operator_on_self)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);
	img |= img;
	
	char copy[] = "or_equal_operator.pgm";
	save_img(img, copy);	

	ASSERT_PASS();

END_TEST


BEGIN_TEST(or_operator_not_on_self)	

	gfx::GrayImage img1(1200, 1200, 255);
	for(size_t i = 0; i < 1200; ++i)
	{
		for(size_t j = 0; j < 1200; ++j)
		{
			img1.set_pixel(i, j, j % 200);
		}			
	}	

	char fileName2[] = "cat.pgm";
	gfx::GrayImage img2 = gfx::load_img(fileName2);

	img1 |= img2;
	
	char copy[] = "or_equal_operator2.pgm";
	save_img(img1, copy);	

	ASSERT_PASS();	
	

END_TEST

//class operator function ^=:

BEGIN_TEST(xor_equal_operator_on_self)

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img = gfx::load_img(fileName);
	img ^= img;
	
	char copy[] = "xor_equal_operator.pgm";
	save_img(img, copy);	

	ASSERT_PASS();	

END_TEST

BEGIN_TEST(xor_equal_operator_not_on_self)	

	gfx::GrayImage img1(1200, 1200, 255);
	for(size_t i = 0; i < 1200; ++i)
	{
		for(size_t j = 0; j < 1200; ++j)
		{
			img1.set_pixel(i, j, j % 200);
		}			
	}	

	char fileName2[] = "cat.pgm";
	gfx::GrayImage img2 = gfx::load_img(fileName2);

	img1 ^= img2;
	
	char copy[] = "xor_equal_operator2.pgm";
	save_img(img1, copy);	

	ASSERT_PASS();	

END_TEST

//class operator function ==:

BEGIN_TEST(is_equal_operator_when_true)	

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img1 = gfx::load_img(fileName);
	gfx::GrayImage img2 = gfx::load_img(fileName);

	int result = img1 == img2;
	
	ASSERT_EQUAL(result, 1);	


END_TEST

BEGIN_TEST(is_equal_operator_when_false)	

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img1 = gfx::load_img(fileName);
	gfx::GrayImage img2(200, 100, 30);

	int result = img1 == img2;
	
	ASSERT_EQUAL(result, 0);
	ASSERT_NOT_EQUAL(img1.size(), img2.size());
	ASSERT_NOT_EQUAL(img1.width(), img2.width());
	ASSERT_NOT_EQUAL(img1.height(), img2.height());

END_TEST

//global operator function !=:

BEGIN_TEST(not_equal_test_when_true)	

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img1 = gfx::load_img(fileName);
	gfx::GrayImage img2(200, 100, 30);

	int result = img1 != img2;
	
	ASSERT_EQUAL(result, 1);
	ASSERT_NOT_EQUAL(img1.size(), img2.size());
	ASSERT_NOT_EQUAL(img1.width(), img2.width());
	ASSERT_NOT_EQUAL(img1.height(), img2.height());	

END_TEST

BEGIN_TEST(not_equal_test_when_false)	

	char fileName[] = "tiger.pgm";
	gfx::GrayImage img1 = gfx::load_img(fileName);
	gfx::GrayImage img2 = gfx::load_img(fileName);

	int result = img1 != img2;
	
	ASSERT_EQUAL(result, 0);
	ASSERT_EQUAL(img1.size(), img2.size());
	ASSERT_EQUAL(img1.width(), img2.width());
	ASSERT_EQUAL(img1.height(), img2.height());
	ASSERT_EQUAL(img1.depth(), img2.depth());	

END_TEST
/*
//global operator function &:

BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST

//global operator function |:

BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST

BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST

//global operator function ^:

BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST

BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST


BEGIN_TEST()	

	ASSERT_PASS();	

END_TEST



*/


BEGIN_SUITE(GrayImage tests run)

	TEST(constructor1_test_size_in_limits_with_depth)
//	TEST(constructor1_test_size_not_in_limits)
	TEST(constructor2_test_size_in_limits_default_depth)
//	TEST(constructor2_test_size_not_in_limits_default_depth)

	TEST(copy_operator_assignment_test_with_self_assignment)
	TEST(copy_operator_assignment_test_not_self_assignment)

	TEST(class_function_get_pixel_in_array)

	TEST(class_function_set_pixel_in_array)

	TEST(class_function_clear_pixel_when_in_array)

	TEST(class_function_to_get_width_test)

	TEST(class_function_to_get_height_test)

	TEST(class_function_to_get_depth_test1)
	TEST(class_function_to_get_depth_test2)

	TEST(class_function_operator_complement_test)

	TEST(class_function_at_test)

	TEST(class_operator_function_round_brackets)

	TEST(global_function_clear_img_test)

	TEST(save_img_test)	

	TEST(load_img_function_test)

	TEST(rotate_img_ninty_deg_clockwise_test)

	TEST(reduce_color_test)

	TEST(scale_down_dims_test)

	TEST(draw_line_test1)

	TEST(draw_line_test2)

	TEST(and_operator_on_self)
	TEST(and_operator_not_on_self)

	TEST(or_operator_on_self)
	TEST(or_operator_not_on_self)

	TEST(xor_equal_operator_on_self)
	TEST(xor_equal_operator_not_on_self)

	TEST(is_equal_operator_when_true)
	TEST(is_equal_operator_when_false)

	TEST(not_equal_test_when_true)
	TEST(not_equal_test_when_false)
/*	
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
	TEST()
*/
END_SUITE