// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <iterator>
#include <string>

using namespace std;

TEST(test_stub) {
  // Add your tests here
  ASSERT_TRUE(true);
}

TEST_MAIN()

TEST(empty_1) {
  BinarySearchTree<int> B_1;
  ASSERT_TRUE(B_1.empty());
  ASSERT_EQUAL(B_1.begin(), B_1.end());
  ASSERT_EQUAL(B_1.find(1), B_1.end());
  int five = 5;
  B_1.insert(five);
  ASSERT_EQUAL(*B_1.begin(), 5);
  ASSERT_FALSE(B_1.empty());
  BinarySearchTree<int> B_2;
  B_2 = B_1;
  ASSERT_FALSE(B_2.empty());
}

TEST(empty_2) {
  BinarySearchTree<double> B_1;
  ASSERT_TRUE(B_1.empty());
  ASSERT_EQUAL(B_1.begin(), B_1.end());
  ASSERT_EQUAL(B_1.find(1), B_1.end());
  double five = 5.0;
  B_1.insert(five);
  ASSERT_EQUAL(*B_1.begin(), 5.0);
  ASSERT_FALSE(B_1.empty());
  BinarySearchTree<double> B_2;
  B_2 = B_1;
  ASSERT_FALSE(B_2.empty());
}

TEST(empty_3) {
  BinarySearchTree<string> B_1;
  ASSERT_TRUE(B_1.empty());
  ASSERT_EQUAL(B_1.begin(), B_1.end());
  string five = "five";
  ASSERT_EQUAL(B_1.find(five), B_1.end());

  B_1.insert(five);
  ASSERT_EQUAL(*B_1.begin(), five);
  ASSERT_FALSE(B_1.empty());
  BinarySearchTree<string> B_2;
  B_2 = B_1;
  ASSERT_FALSE(B_2.empty());
}

TEST(size_1) {
  BinarySearchTree<int> B_1;
  ASSERT_EQUAL(B_1.size(), 0);
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_EQUAL(B_1.size(), 3)
}
TEST(size_2) {
  BinarySearchTree<double> B_1;
  ASSERT_EQUAL(B_1.size(), 0);
  B_1.insert(1.0);
  B_1.insert(2.0);
  B_1.insert(3.0);
  ASSERT_EQUAL(B_1.size(), 3)
}
TEST(size_3) {
  BinarySearchTree<string> B_1;
  ASSERT_EQUAL(B_1.size(), 0);
  string one = "one";
  string two = "two";
  string three = "three";
  B_1.insert(one);
  B_1.insert(two);
  B_1.insert(three);
  ASSERT_EQUAL(B_1.size(), 3)
}

TEST(height_1) {
  BinarySearchTree<int> B_1;
  ASSERT_EQUAL(B_1.size(), 0);
  B_1.insert(1);
  ASSERT_EQUAL(B_1.size(), 1);
  ASSERT_EQUAL(B_1.height(), 1);
  B_1.insert(2);
  ASSERT_EQUAL(B_1.size(), 2);
  ASSERT_EQUAL(B_1.height(), 2);
  B_1.insert(5);
  ASSERT_EQUAL(B_1.size(), 3);
  ASSERT_EQUAL(B_1.height(), 3);
  B_1.insert(3);
  ASSERT_EQUAL(B_1.size(), 4);
  ASSERT_EQUAL(B_1.height(), 4);
  B_1.insert(7);
  ASSERT_EQUAL(B_1.size(), 5);
  ASSERT_EQUAL(B_1.height(), 4);
}

TEST(copy) {
  BinarySearchTree<int> B_1;
  B_1.insert(1);
  B_1.insert(2);
  ASSERT_EQUAL(B_1.size(), 2);
  BinarySearchTree<int> B_2(B_1);
  BinarySearchTree<int>::Iterator i_1 = B_2.begin();
  ASSERT_EQUAL(1, *i_1);
  ++i_1;
  ASSERT_EQUAL(2, *i_1);
}

TEST(find) {
  BinarySearchTree<int> B_1;
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_EQUAL(B_1.size(), 3);
  BinarySearchTree<int>::Iterator i_1 = B_1.begin();
  ASSERT_EQUAL(B_1.find(1), i_1);
  ASSERT_EQUAL(B_1.find(2), ++i_1);
  ASSERT_EQUAL(B_1.find(3), ++i_1);
}

TEST(insert) {
  BinarySearchTree<int> B_1;
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_EQUAL(B_1.size(), 3);
  BinarySearchTree<int>::Iterator i_1 = B_1.begin();
  ASSERT_EQUAL(1, *i_1);
  ASSERT_EQUAL(2, *++i_1);
  // ASSERT_EQUAL(2, *++ ++i_1);
}

TEST(min_max) {
  BinarySearchTree<int> B_1;
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_TRUE(*B_1.min_element() == 1);
  ASSERT_TRUE(*B_1.max_element() == 3);
  B_1.insert(4);
  ASSERT_TRUE(*B_1.min_element() == 1);
  ASSERT_TRUE(*B_1.max_element() == 4);
}

TEST(sort_1) {
  BinarySearchTree<int> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
}

TEST(sort_2) {
  BinarySearchTree<double> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(1.0);
  B_1.insert(2.0);
  B_1.insert(3.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(0.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
}

TEST(sort_3) {
  BinarySearchTree<double> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(5.5);
  B_1.insert(3.3);
  B_1.insert(6.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(7.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto it2 = B_1.begin();
  ++it2;
  *it2 = 5.6;
  ASSERT_TRUE(B_1.check_sorting_invariant());
}

TEST(sort_4) {
  BinarySearchTree<string> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert("apple");
  B_1.insert("banana");
  B_1.insert("cat");
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert("aaaaa");
  ASSERT_TRUE(B_1.check_sorting_invariant());
}

TEST(in_order) {
  BinarySearchTree<int> B_1;

  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  B_1.insert(20);
  B_1.insert(15);
  B_1.insert(12);

  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  ostringstream osin;
  B_1.traverse_inorder(osin);
  ASSERT_EQUAL(osin.str(), "0 1 2 3 12 15 20 ");
}

TEST(preorder) {
  BinarySearchTree<int> B_1;
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  B_1.insert(4);
  ostringstream os;
  B_1.traverse_preorder(os);

  ASSERT_TRUE(os.str() == "1 2 3 4 "); // error
}

TEST(min_greater_than) {
  BinarySearchTree<int> B_1;
  B_1.insert(5);
  ASSERT_EQUAL(1, B_1.size());
  ASSERT_EQUAL(B_1.min_greater_than(5), B_1.end());
  auto i_1 = B_1.begin();
  ASSERT_EQUAL(B_1.min_greater_than(4), i_1);
  B_1.insert(3);
  B_1.insert(25);
  ASSERT_EQUAL(*B_1.min_greater_than(5), 25);
  ASSERT_EQUAL(*B_1.min_greater_than(3), 5);
  ASSERT_EQUAL(B_1.min_greater_than(25), B_1.end());
}

TEST(min_greater_than_1) {
  BinarySearchTree<int> B_1;
  ASSERT_TRUE(B_1.empty());
  ASSERT_EQUAL(B_1.min_greater_than(5), B_1.end());
}

TEST(min_greater_than_2) {
  BinarySearchTree<double> B_1;
  B_1.insert(5.0);
  ASSERT_EQUAL(1, B_1.size());
  ASSERT_EQUAL(B_1.min_greater_than(5.0), B_1.end());
  ASSERT_EQUAL(*B_1.min_greater_than(4.0), 5.0);
  B_1.insert(3.0);
  B_1.insert(25.0);
  ASSERT_EQUAL(*B_1.min_greater_than(5.0), 25.0);
  ASSERT_EQUAL(*B_1.min_greater_than(3.0), 5.0);
  ASSERT_EQUAL(B_1.min_greater_than(25.0), B_1.end());
}

TEST(min_greater_than_3) {
  BinarySearchTree<string> B_1;
  B_1.insert("dog");
  ASSERT_EQUAL(1, B_1.size());
  ASSERT_EQUAL(B_1.min_greater_than("dog"), B_1.end());
  B_1.insert("apple");
  B_1.insert("banana");
  ASSERT_EQUAL(B_1.min_greater_than("dog"), B_1.end());
  ASSERT_EQUAL(*B_1.min_greater_than("banana"), "dog");
}

TEST(check_sorting_invariant) {
  BinarySearchTree<int> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(1);
  B_1.insert(2);
  B_1.insert(3);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto i_1 = B_1.begin(); // 0 1 2 3
  ++ ++ ++i_1;
  *i_1 = 6;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto i_2 = B_1.begin();
  *i_2 = 10;
  ASSERT_FALSE(B_1.check_sorting_invariant());
}

TEST(a) {
  BinarySearchTree<int> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(5);
  ASSERT_TRUE(*B_1.max_element() = 5);
  ASSERT_TRUE(*B_1.min_element() = 5);
  ASSERT_TRUE(B_1.min_greater_than(1) == B_1.begin());
  ASSERT_TRUE(B_1.min_greater_than(6) == B_1.end());
  ASSERT_TRUE(B_1.size() == 1);
  ASSERT_TRUE(B_1.find(5)==B_1.begin());
}

TEST(check_sorting_invariant_1) {
  BinarySearchTree<double> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(5.0);
  B_1.insert(55.0);
  B_1.insert(15.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(25.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto i_1 = B_1.begin(); // 5 15 25 55
  ++ ++ ++i_1;
  *i_1 = 66.0;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto i_2 = B_1.begin();
  *i_2 = 100.0;
  ASSERT_FALSE(B_1.check_sorting_invariant());
}

TEST(check_sorting_invariant_2) {
  BinarySearchTree<double> B_1;
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(5.0);
  B_1.insert(55.0);
  B_1.insert(15.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  B_1.insert(25.0);
  ASSERT_TRUE(B_1.check_sorting_invariant());
  auto i_1 = B_1.begin(); // 5 15 25 55
  ++ ++i_1;
  *i_1 = 65;
  ASSERT_FALSE(B_1.check_sorting_invariant());
}
