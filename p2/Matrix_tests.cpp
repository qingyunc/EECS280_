// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include <sstream>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}





TEST(test_print) {
  ostringstream oss;
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, 11);
  Matrix_print(mat, oss);
  string str = oss.str();
  string str_correct = "3 5\n11 11 11 \n11 11 11 \n11 11 11 \n11 11 11 \n11 11 11 \n";
  Matrix_print(mat, oss);
  ASSERT_EQUAL(str, str_correct)


  ostringstream osss;
  Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 1, 5);
  Matrix_fill(mat1, 10);
    Matrix_print(mat1, osss);
  string str1 = osss.str();
  string str_correct1 = "1 5\n10 \n10 \n10 \n10 \n10 \n";
  Matrix_print(mat1, osss);
  ASSERT_EQUAL(str1, str_correct1)

  ostringstream ossss;
  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 5, 1);
  Matrix_fill(mat2, 9);
      Matrix_print(mat2, ossss);
  string str2 = ossss.str();
  string str_correct2 = "5 1\n9 9 9 9 9 \n";
  Matrix_print(mat2, ossss);
  ASSERT_EQUAL(str2, str_correct2)
  delete mat;
  delete mat1;
  delete mat2;

}

TEST(test_width_height){
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  Matrix_width(mat);
  Matrix_height(mat);
  ASSERT_EQUAL(3, Matrix_width(mat))
  ASSERT_EQUAL(5, Matrix_height(mat))

 Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 3, 2);
  Matrix_width(mat1);
  Matrix_height(mat1);
  ASSERT_EQUAL(3, Matrix_width(mat1));
  ASSERT_EQUAL(2, Matrix_height(mat1))

  delete mat;
  delete mat1;
}

TEST(test_index){
Matrix *mat = new Matrix;
Matrix_init(mat, 3, 5 );
int* ptr = Matrix_at(mat, 0, 0);
ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
ASSERT_EQUAL(Matrix_column(mat, ptr), 0);

delete mat;


Matrix *mat1 = new Matrix;
Matrix_init(mat1, 100, 100 );
int* ptr1 = Matrix_at(mat1, 99, 99);
ASSERT_EQUAL(Matrix_row(mat1, ptr1), 99);
ASSERT_EQUAL(Matrix_column(mat1, ptr1), 99);

delete mat1;


Matrix *mat2 = new Matrix;
Matrix_init(mat2, 100, 1 );
int* ptr2 = Matrix_at(mat2, 0, 0);
ASSERT_EQUAL(Matrix_row(mat2, ptr2), 0);
ASSERT_EQUAL(Matrix_column(mat2, ptr2), 0);

delete mat2;

Matrix *mat3 = new Matrix;
Matrix_init(mat3, 1, 100 );
int* ptr3 = Matrix_at(mat3, 63, 0);
ASSERT_EQUAL(Matrix_row(mat3, ptr3), 63);
ASSERT_EQUAL(Matrix_column(mat3, ptr3), 0);

delete mat3;

Matrix *mat4 = new Matrix;
Matrix_init(mat4, 1, 1 );
int* ptr4 = Matrix_at(mat4, 0, 0);
ASSERT_EQUAL(Matrix_row(mat4, ptr4), 0);
ASSERT_EQUAL(Matrix_column(mat4, ptr4), 0);

delete mat4;
}

TEST(test_matrix_at){
Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3 );
  Matrix_fill(mat, 4);
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 5; column++){
      ASSERT_EQUAL(*Matrix_at(mat, row, column), 4);
    }
  }
   ASSERT_EQUAL(*Matrix_at(mat, 1, 2), 4);

  delete mat;

Matrix *mat1 = new Matrix;
  Matrix_init(mat1, 55, 1 );
  Matrix_fill(mat1, 15);
  for(int row1 = 0; row1 < 1; row1++){
    for(int column1 = 0; column1 < 55; column1++){
      ASSERT_EQUAL(*Matrix_at(mat1, row1, column1), 15);
    }
  }

  int* ptr = Matrix_at(mat1, 0, 16);
  *ptr = 48;
  ASSERT_EQUAL(*Matrix_at(mat1, 0, 16), 48);
  delete mat1;

  Matrix *mat2 = new Matrix;
  Matrix_init(mat2, 1, 400 );
  Matrix_fill(mat2, 33);
  for(int row2 = 0; row2 < 400; row2++){
    for(int column2 = 0; column2 < 1; column2++){
      ASSERT_EQUAL(*Matrix_at(mat2, row2, column2), 33);
    }
  }


  int* ptr2 = Matrix_at(mat2, 200, 0);
  *ptr2 = 77;
  ASSERT_EQUAL(*Matrix_at(mat2, 200, 0), 77);
  delete mat2;


  Matrix *mat3 = new Matrix;
  Matrix_init(mat3, 1, 1 );
  Matrix_fill(mat3, 88);
  for(int row3 = 0; row3 < 1; row3++){
    for(int column3 = 0; column3 < 1; column3++){
      ASSERT_EQUAL(*Matrix_at(mat3, row3, column3), 88);
    }
  }

  int* ptr3 = Matrix_at(mat3, 0, 0);
  *ptr3 = 99;

  ASSERT_EQUAL(*Matrix_at(mat3, 0, 0), 99);
  delete mat3;

 Matrix *mat4 = new Matrix;
  Matrix_init(mat4, 5, 3 );
  Matrix_fill(mat4, -4);
  for(int row4 = 0; row4 < 3; row4++){
    for(int column4 = 0; column4 < 5; column4++){
      ASSERT_EQUAL(*Matrix_at(mat4, row4, column4), -4);
    }
  }
   ASSERT_EQUAL(*Matrix_at(mat4, 1, 2), -4);

  delete mat4;
}


TEST(matrix_constant_at){
Matrix* mat = new Matrix;
int width = 1;
int height = 1;
Matrix_init(mat, 1, 1);
Matrix_fill(mat, 22);
const Matrix* ptr = mat;
  for (int row = 0; row < height; row++) {
      for (int column = 0; column < width; column++) {
            ASSERT_EQUAL(*Matrix_at(ptr, row, column), 22);
      }
  }
    delete mat;


Matrix* mat1 = new Matrix;
Matrix_init(mat1, 500, 1);
Matrix_fill(mat1, 88);
const Matrix* ptr1 = mat1;
  for (int row1 = 0; row1 < height; row1++) {
      for (int column1 = 0; column1 < width; column1++) {
            ASSERT_EQUAL(*Matrix_at(ptr1, row1, column1), 88);
      }
  }
    delete mat1;

Matrix* mat2 = new Matrix;
Matrix_init(mat2, 1, 500);
Matrix_fill(mat2, 44);
const Matrix* ptr2 = mat2;
  for (int row2 = 0; row2 < height; row2++) {
      for (int column2 = 0; column2 < width; column2++) {
            ASSERT_EQUAL(*Matrix_at(ptr2, row2, column2),44);
      }
  }
    delete mat2;

Matrix* mat3 = new Matrix;
Matrix_init(mat3, 444, 444);
Matrix_fill(mat3, 222);
const Matrix* ptr3 = mat3;
  for (int row3 = 0; row3 < height; row3++) {
      for (int column3 = 0; column3 < width; column3++) {
            ASSERT_EQUAL(*Matrix_at(ptr3, row3, column3),222);
      }
  }
    delete mat3;


}


TEST(matri_fill){
    Matrix *mat = new Matrix;
    Matrix *ma = new Matrix;
    int width = 1;
    int height = 1;
    Matrix_init(mat, width, height);
    Matrix_init(ma, width, height);
    Matrix_fill(mat, 600);
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++){
            int* ptr = Matrix_at(ma, row, column);
            *ptr = 600;
        }
    }
    ASSERT_TRUE(Matrix_equal(mat, ma));
    
    delete mat;
    delete ma;


    Matrix *mat1 = new Matrix;
    Matrix *ma1 = new Matrix;
    int width1 = 500;
    int height1 = 1;
    Matrix_init(mat1, width1, height1);
    Matrix_init(ma1, width1, height1);
    Matrix_fill(mat1, 88);
    for (int row1 = 0; row1 < height1; row1++) {
        for (int column1 = 0; column1 < width1; column1++){
            int* ptr1 = Matrix_at(ma1, row1, column1);
            *ptr1 = 88;
        }
    }
    ASSERT_TRUE(Matrix_equal(mat1, ma1));
    
    delete mat1;
    delete ma1;

    Matrix *mat2 = new Matrix;
    Matrix *ma2 = new Matrix;
    int width2 = 1;
    int height2 = 500;
    Matrix_init(mat2, width2, height2);
    Matrix_init(ma2, width2, height2);
    Matrix_fill(mat2, 300);
    for (int row2 = 0; row2 < height2; row2++) {
        for (int column2 = 0; column2 < width2; column2++){
            int* ptr2 = Matrix_at(ma2, row2, column2);
            *ptr2 = 300;
        }
    }
    ASSERT_TRUE(Matrix_equal(mat2, ma2));
    
    delete mat2;
    delete ma2;


    Matrix *mat3 = new Matrix;
    Matrix *ma3 = new Matrix;
    int width3 = 500;
    int height3 = 500;
    Matrix_init(mat3, width3, height3);
    Matrix_init(ma3, width3, height3);
    Matrix_fill(mat3, 88);
    for (int row3 = 0; row3 < height3; row3++) {
        for (int column3 = 0; column3 < width3; column3++){
            int* ptr3 = Matrix_at(ma3, row3, column3);
            *ptr3 = 88;
        }
    }
    ASSERT_TRUE(Matrix_equal(mat3, ma3));
    
    delete mat3;
    delete ma3;
}

TEST(fill_border){
Matrix* mat = new Matrix;
Matrix_init(mat, 1, 1);
Matrix_fill(mat, 5);
int* ptr = Matrix_at(mat, 0, 0);
Matrix_fill_border(mat, 5);
ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
delete mat;

Matrix* mat1 = new Matrix;
Matrix_init(mat1, 500, 1);
Matrix_fill(mat1, 6);
int* ptr1 = Matrix_at(mat1, 0, 0);
Matrix_fill_border(mat1, 5);
ASSERT_EQUAL(Matrix_row(mat1, ptr1), 0);
ASSERT_EQUAL(Matrix_column(mat1, ptr1), 0);
delete mat1;


Matrix* mat2 = new Matrix;
Matrix_init(mat2, 1, 500);
Matrix_fill(mat2, 7);
int* ptr2 = Matrix_at(mat2, 0, 0);
Matrix_fill_border(mat2, 5);
ASSERT_EQUAL(Matrix_row(mat2, ptr2), 0);
ASSERT_EQUAL(Matrix_column(mat2, ptr2), 0);
delete mat2;



Matrix* mat3 = new Matrix;
Matrix_init(mat3, 500, 500);
Matrix_fill(mat3, 7);
int* ptr3 = Matrix_at(mat3, 499, 499);
Matrix_fill_border(mat3, 5);
ASSERT_EQUAL(Matrix_row(mat3, ptr3), 499);
ASSERT_EQUAL(Matrix_column(mat3, ptr3),499);
//delete mat3;
for (int i = 0; i < 500; ++i) {
  for (int j = 0; j < 500; ++j) {
    if (i == 0 || i == 499 || j == 0 || j == 499) {
      ASSERT_EQUAL(*Matrix_at(mat3, i, j), 5);
    } else {
       ASSERT_EQUAL(*Matrix_at(mat3, i, j), 7);
    }
  }
}
delete mat3;
}


TEST(max_min_mincolumn){
  Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, 20);
    ASSERT_EQUAL(Matrix_max(mat), 20);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,1),0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,1), 20);

 Matrix* mat1 = new Matrix;
    Matrix_init(mat1, 50, 50);
    Matrix_fill(mat1, 20);
    ASSERT_EQUAL(Matrix_max(mat1), 20);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat1,49,0,50),0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat1,49,0,50), 20);
    Matrix_fill_border(mat1, -20);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat1, 49, 0, 50), -20);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat1, 49, 0, 50), 0);
    delete mat1;
     delete mat;




    




}















































// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here





