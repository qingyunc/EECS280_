// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"
#include <cassert>
#include <string>

using namespace std;

// Add your test cases here

TEST(test_stub) {
  // Add test code here
  ASSERT_TRUE(true);
}
TEST(list_constructor) {
  List<int> list;
  ASSERT_EQUAL(0, list.size());
  ASSERT_TRUE(list.empty());

  List<string> list_1;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_1.push_back(one);
  list_1.push_back(two);
  list_1.push_back(three);
  list_1.push_back(four);
  list_1.push_back(five);
  ASSERT_EQUAL(5, list_1.size());
  ASSERT_FALSE(list_1.empty());
}

TEST(front_back_case1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(one_half, list_2.front());
  ASSERT_EQUAL(five, list_2.back());
}
TEST(front_back_case2) {
  List<string> list_2;
  string one = "one";
  list_2.push_back(one);
  ASSERT_EQUAL(one, list_2.front());
  ASSERT_EQUAL(one, list_2.back());
}

TEST(push_front_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(one_half, list_2.front());
}

TEST(push_front_2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int six = 6;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  ASSERT_EQUAL(6, list_2.front());
}

TEST(push_front_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double six = 6.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  ASSERT_EQUAL(6.0, list_2.front());
}

TEST(push_front_4) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_front(one_half);
  ASSERT_EQUAL(one_half, list_2.front());
}

TEST(push_front_5) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(one_half, list_2.front());
}

TEST(push_back_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);

  ASSERT_EQUAL(one, list_2.front());
  ASSERT_EQUAL(five, list_2.back());
}

TEST(push_back_2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int six = 6;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  ASSERT_EQUAL(5, list_2.back());
}
TEST(push_back_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double six = 6.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  ASSERT_EQUAL(5.0, list_2.back())
}

TEST(push_back_4) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_front(one_half);
  ASSERT_EQUAL(one_half, list_2.back());
}

TEST(push_back_5) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(five, list_2.back());
}

TEST(pop__1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.pop_front();
  list_2.pop_back();

  ASSERT_EQUAL(two, list_2.front());
  ASSERT_EQUAL(four, list_2.back());
}

TEST(pop__2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int six = 6;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  list_2.pop_front();
  list_2.pop_back();

  ASSERT_EQUAL(1, list_2.front());
  ASSERT_EQUAL(4, list_2.back());
}
TEST(pop_front_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double six = 6.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  list_2.pop_front();
  list_2.pop_back();
  ASSERT_EQUAL(4.0, list_2.back());
  ASSERT_EQUAL(1.0, list_2.front());
}

TEST(pop_4) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_front(one_half);
  list_2.pop_front();
  ASSERT_TRUE(list_2.empty());
}

TEST(pop_4_2) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_front(one_half);
  list_2.pop_back();
  ASSERT_TRUE(list_2.empty());
}

TEST(pop_5) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(five);
  list_2.push_front(one_half);
  list_2.pop_back();
  list_2.pop_front();
  ASSERT_TRUE(list_2.empty());

  // ASSERT_NOT_EQUAL(five, list_2.back());
}

TEST(pop_6) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);

  list_2.pop_front();
  ASSERT_EQUAL(five, list_2.back());
  ASSERT_EQUAL(one, list_2.front());
  list_2.pop_back();
  ASSERT_EQUAL(four, list_2.back());
  ASSERT_EQUAL(one, list_2.front());
  list_2.pop_back();
  list_2.pop_back();
  list_2.pop_back();
  list_2.pop_back();
  ASSERT_TRUE(list_2.empty());
}

TEST(clear_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  ASSERT_FALSE(list_2.empty());

  list_2.clear();

  ASSERT_TRUE(list_2.empty());
}

TEST(clear_2) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  ASSERT_TRUE(list_2.empty());

  list_2.clear();

  ASSERT_TRUE(list_2.empty());
}

TEST(copy_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  List<string> list_3(list_2);

  ASSERT_EQUAL(one_half, list_3.front());
}

TEST(copy_2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int six = 6;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  List<int> list_3(list_2);
  ASSERT_EQUAL(6, list_3.front());
}

TEST(copy_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double six = 6.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(six);
  List<double> list_3(list_2);
  ASSERT_EQUAL(6.0, list_3.front());
}

TEST(copy_4) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_front(one_half);
  List<string> list_3(list_2);
  ASSERT_EQUAL(one_half, list_3.front());
}

TEST(copy_5) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(five);
  list_2.push_front(one_half);
  List<string> list_3(list_2);
  ASSERT_EQUAL(one_half, list_3.front());
}

TEST(oprator_equal_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  List<string> list_3;
  list_3.push_back(one);

  list_3 = list_2;

  List<string>::Iterator begin_3 = list_3.begin();
  List<string>::Iterator begin_2 = list_2.begin();

  ASSERT_EQUAL(list_2.size(), list_2.size());
  while (begin_2 != list_2.end()) {
    ASSERT_EQUAL(*begin_3, *begin_2);
    ++begin_2;
    ++begin_3;
  }
}

TEST(oprator_equal_2) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  List<string> list_3;

  list_3 = list_2;

  List<string>::Iterator begin_3 = list_3.begin();
  List<string>::Iterator begin_2 = list_2.begin();

  ASSERT_EQUAL(list_2.size(), list_2.size());
  while (begin_2 != list_2.end()) {
    ASSERT_EQUAL(*begin_3, *begin_2);
    ++begin_2;
    ++begin_3;
  }
}

TEST(oprator_equal_3) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  List<string> list_3;

  list_3.push_back(one);
  list_3.push_back(two);
  list_3.push_back(three);
  list_3.push_back(four);
  list_3.push_back(five);
  list_3.push_front(one_half);

  list_3 = list_2;

  List<string>::Iterator begin_3 = list_3.begin();
  List<string>::Iterator begin_2 = list_2.begin();

  ASSERT_EQUAL(list_2.size(), list_2.size());
  while (begin_2 != list_2.end()) {
    ASSERT_EQUAL(*begin_3, *begin_2);
    ++begin_2;
    ++begin_3;
  }
}

TEST(operator_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);

  // 1/2 1 2 3 4 5
  List<string>::Iterator begin_1 = list_2.begin();

  // size
  ASSERT_EQUAL(6, list_2.size())
  //

  ASSERT_EQUAL(one_half, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(one, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(two, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(three, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(four, *begin_1);
  ++begin_1;
}
TEST(operator_2) {

  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int one_half = 0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);

  // 1/2 1 2 3 4 5
  List<int>::Iterator begin_1 = list_2.begin();

  // size
  ASSERT_EQUAL(6, list_2.size());
  //

  ASSERT_EQUAL(0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(1, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(2, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(3, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(4, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(5, *begin_1);
  --begin_1;
  ASSERT_EQUAL(4, *begin_1);
  --begin_1;
  ASSERT_EQUAL(3, *begin_1);
  --begin_1;
  ASSERT_EQUAL(2, *begin_1);
  --begin_1;
  ASSERT_EQUAL(1, *begin_1);
  --begin_1;
  ASSERT_EQUAL(0, *begin_1);
}

TEST(operator_3) {

  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double one_half = 0.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);

  // 0 1 2 3 4 5
  List<double>::Iterator begin_1 = list_2.begin();

  // size
  ASSERT_EQUAL(6, list_2.size());
  //

  ASSERT_EQUAL(0.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(1.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(2.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(3.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(4.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(5.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(4.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(3.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(2.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(1.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(0.0, *begin_1);
}

TEST(equal_not_equal_1) {
  List<string> list_1;
  string one = "one";
  string two = "two";
  string three = "three";

  list_1.push_back(one);
  list_1.push_back(two);
  list_1.push_back(three);

  ASSERT_EQUAL(3, list_1.size());
  List<string>::Iterator begin_1 = list_1.begin();
  List<string>::Iterator begin_1_1 = list_1.begin();
  ASSERT_EQUAL(begin_1, begin_1_1);

  //  1 2 3
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
}

TEST(equal_not_equal_2) {

  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int one_half = 0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());
  List<int>::Iterator begin_1 = list_2.begin();
  List<int>::Iterator begin_1_1 = list_2.begin();
  ASSERT_EQUAL(begin_1, begin_1_1);

  // 1/2 1 2 3 4 5
  ++begin_1;
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
}

TEST(equal_not_equal_3) {

  List<double> list_3;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double one_half = 0.0;

  list_3.push_back(one);
  list_3.push_back(two);
  list_3.push_back(three);
  list_3.push_back(four);
  list_3.push_back(five);
  list_3.push_front(one_half);
  ASSERT_EQUAL(6, list_3.size());
  List<double>::Iterator begin_1 = list_3.begin();
  List<double>::Iterator begin_1_1 = list_3.begin();
  ASSERT_EQUAL(begin_1, begin_1_1);

  // 1/2 1 2 3 4 5
  ++begin_1;
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
  ++begin_1;
  ASSERT_NOT_EQUAL(begin_1, begin_1_1)
  ++begin_1_1;
  ASSERT_EQUAL(begin_1, begin_1_1);
}

TEST(change_1) {

  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";
  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());
  List<string>::Iterator begin_1 = list_2.begin();
  *begin_1 = one_half;
  ASSERT_EQUAL(one_half, list_2.front());
  ++begin_1;
  ASSERT_EQUAL(one, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(two, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(three, *begin_1);
  --begin_1;
  ASSERT_EQUAL(two, *begin_1);
  --begin_1;
  ASSERT_EQUAL(one, *begin_1);
  --begin_1;
  ASSERT_EQUAL(one_half, *begin_1);
}

// TEST(change_2) {
//
//   List<int> list_2;
//   int one = 1;
//   int two = 2;
//   int three = 3;
//   int four = 4;
//   int five = 5;
//   int one_half = 0;
//   list_2.push_back(one);
//   list_2.push_back(two);
//   list_2.push_back(three);
//   list_2.push_back(four);
//   list_2.push_back(five);
//   list_2.push_front(one_half);
//   ASSERT_EQUAL(6, list_2.size());
//   List<int>::Iterator begin_1 = list_2.begin();
//   *begin_1 = 0;
//   ASSERT_EQUAL(0, list_2.front());
//   ++begin_1;
//   ASSERT_EQUAL(1, *begin_1);
//   ++begin_1;
//   ASSERT_EQUAL(2, *begin_1);
//   ++begin_1;
//   ASSERT_EQUAL(3, *begin_1);
//   ++begin_1;
//   ASSERT_EQUAL(4, *begin_1);
//   ++begin_1;
//   ASSERT_EQUAL(5, *begin_1);
//   --begin_1;
//   ASSERT_EQUAL(4, *begin_1);
//   --begin_1;
//   ASSERT_EQUAL(3, *begin_1);
//   --begin_1;
//   ASSERT_EQUAL(2, *begin_1);
// }

TEST(change_3) {

  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double one_half = 0.0;
  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());

  List<double>::Iterator begin_1 = list_2.begin();
  *begin_1 = 0.0;
  ASSERT_EQUAL(0.0, list_2.front());
  ++begin_1;
  ASSERT_EQUAL(1.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(2.0, *begin_1);
  ++begin_1;
  ASSERT_EQUAL(3.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(2.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(1.0, *begin_1);
  --begin_1;
  ASSERT_EQUAL(0.0, *begin_1);
}

TEST(erase_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";
  string one_half = "one_half";
  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());
  List<string>::Iterator i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_EQUAL(*list_2.begin(), one);
  List<string>::Iterator i_2 = list_2.begin();
  list_2.erase(i_2);
  ASSERT_EQUAL(*list_2.begin(), two);
}
TEST(erase_2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;
  int one_half = 0;
  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());
  List<int>::Iterator i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_EQUAL(*list_2.begin(), 1);
  List<int>::Iterator i_2 = list_2.begin();
  list_2.erase(i_2);
  ASSERT_EQUAL(*list_2.begin(), 2);
}

TEST(erase_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;
  double one_half = 0.0;
  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);
  list_2.push_front(one_half);
  ASSERT_EQUAL(6, list_2.size());
  List<double>::Iterator i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_EQUAL(*list_2.begin(), 1.0);
  List<double>::Iterator i_2 = list_2.begin();
  list_2.erase(i_2);
  ASSERT_EQUAL(*list_2.begin(), 2.0);
}

TEST(erase_4) {
  List<int> list_2;
  int one = 1;

  list_2.push_back(one);

  ASSERT_EQUAL(1, list_2.size());

  List<int>::Iterator i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_TRUE(list_2.empty());
}

TEST(erase_5) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);

  ASSERT_EQUAL(3, list_2.size());

  List<int>::Iterator i_1 = list_2.begin();
  ++i_1;
  ++i_1;

  list_2.erase(i_1);
  ASSERT_EQUAL(2, list_2.back());
  i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_EQUAL(2, list_2.front());
  i_1 = list_2.begin();
  list_2.erase(i_1);
  ASSERT_TRUE(list_2.empty());
}

TEST(insert_1) {
  List<string> list_2;
  string one = "one";
  string two = "two";
  string three = "three";
  string four = "four";
  string five = "five";

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);

  ASSERT_EQUAL(5, list_2.size());

  List<string>::Iterator i_1 = list_2.begin();

  list_2.insert(i_1, "point_5");

  ASSERT_EQUAL(*list_2.begin(), "point_5");

  --i_1;

  ASSERT_EQUAL(*i_1, "point_5");
  list_2.insert(i_1, "zero");
  --i_1;
  ASSERT_EQUAL(*i_1, "zero");
}

TEST(insert_2) {
  List<int> list_2;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);

  ASSERT_EQUAL(5, list_2.size());

  List<int>::Iterator i_1 = list_2.begin();

  list_2.insert(i_1, 1);

  ASSERT_EQUAL(*list_2.begin(), 1);

  --i_1;

  ASSERT_EQUAL(*i_1, 1);
  list_2.insert(i_1, 0);
  --i_1;
  ASSERT_EQUAL(*i_1, 0);
}

TEST(insert_2_2) {
  List<int> list_1;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;

  list_1.push_back(one);
  list_1.push_back(two);
  list_1.push_back(three);
  list_1.push_back(four);

  ASSERT_EQUAL(4, list_1.size());
  List<int>::Iterator i_1 = list_1.begin();

  ++ ++i_1;
  list_1.insert(i_1, 5);
  ASSERT_EQUAL(5, list_1.size());
  List<int>::Iterator i_2 = list_1.begin();

  ++ ++i_2;

  ASSERT_EQUAL(5, *i_2);
}

TEST(insert_3) {
  List<double> list_2;
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double four = 4.0;
  double five = 5.0;

  list_2.push_back(one);
  list_2.push_back(two);
  list_2.push_back(three);
  list_2.push_back(four);
  list_2.push_back(five);

  ASSERT_EQUAL(5, list_2.size());

  List<double>::Iterator i_1 = list_2.begin();

  list_2.insert(i_1, 0.5);

  ASSERT_EQUAL(*list_2.begin(), 0.5);

  --i_1;

  ASSERT_EQUAL(*i_1, 0.5);
  list_2.insert(i_1, 0);
  --i_1;
  ASSERT_EQUAL(*i_1, 0);
}

TEST(insert_4) {
  List<int> list_2;
  List<int>::Iterator i_1 = list_2.begin();
  ASSERT_TRUE(list_2.empty());

  int one = 1;
  list_2.push_back(one);
  ASSERT_EQUAL(1, list_2.size());
  list_2.insert(i_1, 0);
  ASSERT_EQUAL(*list_2.begin(), 1);
  list_2.insert(i_1, 0);
}

TEST(insert_5) {
  List<int> list_2;
  List<int>::Iterator i_1 = list_2.end();
  ASSERT_TRUE(list_2.empty());

  list_2.push_front(1);
  list_2.push_back(2);
  list_2.push_back(3);
  list_2.insert(i_1, 4);

  ASSERT_EQUAL(4, list_2.size());
  List<int>::Iterator i_2 = list_2.begin();
  ++ ++ ++i_2;

  ASSERT_EQUAL(*i_2, 4);
}

TEST_MAIN()
