/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */
#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath> 
#include <iostream> 
#include <limits>
using namespace std;

void test_count_small_data_set();
void test_sum_small_data_set();
void test_mean_small_data_set();
void test_median_small_data_set();
void test_mode_small_data_set();
void test_min_small_data_set();
void test_max_small_data_set();
void test_stdev_small_data_set();
void test_percentile_small_data_set();

// Add prototypes for you test functions here.
int main() {
  test_count_small_data_set();
  test_sum_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_stdev_small_data_set();
  test_percentile_small_data_set();
  // Call your test functions here
return 0;
}

void test_count_small_data_set() {
  cout << "test_count_small_data_set" << endl;

vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(count(data) == 3);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(sum(data_1) == 3);
cout << "PASS!" << endl;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(sum(data) == 6);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(sum(data_1) == 3);
cout << "PASS!" << endl;
  }

void test_mean_small_data_set() {
  cout << "test_mean_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(mean(data) == 2);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(mean(data_1) == 1);
cout << "PASS!" << endl;
  }

void test_median_small_data_set() {
  cout << "test_median_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(median(data) == 2);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(median(data_1) == 1);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(3);
  data_2.push_back(4);

assert(median(data_2) == 2.5);


cout << "PASS!" << endl;
  }

void test_mode_small_data_set() {
  cout << "test_mode_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(mode(data) == 1);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(mode(data_1) == 1);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(2);
  data_2.push_back(4);

assert(mode(data_2) == 2);


cout << "PASS!" << endl;
  }

void test_min_small_data_set() {
  cout << "test_min_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(min(data) == 1);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(min(data_1) == 1);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(2);
  data_2.push_back(4);

assert(min(data_2) == 1);


cout << "PASS!" << endl;
  }


void test_max_small_data_set() {
  cout << "test_max_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(max(data) == 3);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(max(data_1) == 1);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(2);
  data_2.push_back(4);

assert(max(data_2) == 4);


cout << "PASS!" << endl;
  }


void test_stdev_small_data_set() {
  cout << "test_stdev_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(stdev(data) == 1);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(stdev(data_1) == 0);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(2);
  data_2.push_back(4);
  const double epsilon = 0.00001;
  cout.precision(std::numeric_limits<double>::max_digits10);
assert((abs(stdev(data_1) - 1.2583057392118) < epsilon));
cout << "PASS!" << endl;
  }


void test_percentile_small_data_set() {
  cout << "test_percentile_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
assert(percentile(data, 0.5) == 2);

vector<double> data_1;
  data_1.push_back(1);
  data_1.push_back(1);
  data_1.push_back(1);
assert(percentile(data_1,0.5) == 1);

vector<double> data_2;
  data_2.push_back(1);
  data_2.push_back(2);
  data_2.push_back(2);
  data_2.push_back(4);
assert(percentile(data_2,0.5) == 2);
cout << "PASS!" << endl;
  }







// Add the test function implementations here.
