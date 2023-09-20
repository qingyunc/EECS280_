// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
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

int main() {
  cout << "enter a filename" << endl;
  string filename = "";
  cin >> filename;
  cout << "enter a column name" << endl;
  string column = "";
  cin >> column;
  cout << "reading column " << column << " from " <<  filename << endl;

  cout << "Summary (value: frequency)" << endl;
  vector<double> v = extract_column(filename, column);
  vector<vector<double>> sum_of_vector= summarize(v);
  for (int i = 0; i < sum_of_vector.size(); ++i){
    cout << sum_of_vector[i][0] << ": " << sum_of_vector[i][1] << endl;
}

cout << endl;
cout << "count = " << count(v) << endl;
cout << "sum = " << sum(v) << endl;
cout << "mean = " << mean(v) << endl;
cout << "stdev = " << stdev(v) << endl;
cout << "median = " << median(v) << endl;
cout << "mode = " << mode(v) << endl;
cout << "min = " << min(v) << endl;
cout << "max = " << max(v) << endl;

cout << "  0th percentile = " << percentile(v, 0.0)
     << endl;
cout << " 25th percentile = " << percentile(v, 0.25)
     << endl;
cout << " 50th percentile = " << percentile(v, 0.50)
     << endl;
cout << " 75th percentile = " << percentile(v, 0.75)
     << endl;
cout << "100th percentile = " << percentile(v, 1)
     << endl;
}