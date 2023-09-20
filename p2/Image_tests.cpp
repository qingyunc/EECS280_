// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}



TEST(image_init){
  Image *img = new Image;
  Image_init(img, 5, 3);
  ASSERT_EQUAL(5, Image_width(img));
  ASSERT_EQUAL(3, Image_height(img));

  delete img;
  
  
  Image *img1 = new Image;
  Image_init(img1, 1, 1);
  ASSERT_EQUAL(1, Image_width(img1));
  ASSERT_EQUAL(1, Image_height(img1));

  delete img1;

  Image *img2 = new Image;
  Image_init(img2, 1, 10);
  ASSERT_EQUAL(1, Image_width(img2));
  ASSERT_EQUAL(10, Image_height(img2));

  delete img2;

}

TEST(image_init2){
  
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";

  stringstream is;
  is << "P3\n2 2\n255\n";
  is << "255 0 0 0 255 0 \n";
  is << "0 0 255 255 255 255 \n";
  
  Image *img = new Image;
  Image_init(img, is);
  ostringstream os;

  Image_print(img, os);

  ASSERT_EQUAL(correct.str(), os.str());
  delete img;
}

TEST(Image_set_get_pixel){
  Image *img = new Image;

  Image_init(img, 465, 365);
  const Pixel blue = {0, 0, 255};
   const Pixel red = {255, 0, 0};
   Image_fill(img, blue);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 364, 464), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 364, 0), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 464), blue));

  Image_set_pixel(img, 0, 0, red);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), blue));

 delete img;
}


TEST(fillout){
  Image *img = new Image;
  const Pixel blue = {0, 0, 255};
  const Pixel red = {255, 0, 0};
  Image_init(img, 5, 5);
   
  Image_fill(img, blue);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 4), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 0), blue));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 4), blue));

 Image_fill(img, red);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 4), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 0), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 4), red));
  delete img;
}



































































// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
