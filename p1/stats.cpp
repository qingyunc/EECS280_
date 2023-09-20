// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath> 
#include <iostream> 
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
  sort(v);
  vector < vector <double>> result;
  for (int i = 0; i < v.size(); ++i){
    bool repeat = false;
    for (int j = 0; j <result.size(); ++j){
      if (result[j][0] == v[i]){
         result[j][1]+=1;
         repeat = true;
      }
    }
    if (repeat == false){
      double f = v[i];
      vector<double> ff = {f, 1};
      result.push_back(ff);
    }
}
return result;
}

int count(vector<double> v) {
  return v.size();
}

double sum(vector<double> v) {
  double total = 0;
  for (int i = 0; i < v.size(); ++i) {
    total += v[i];
  }
  return total;
  }

double mean(vector<double> v) {
  return sum(v)/count(v);
}

double median(vector<double> v) {
  sort(v);
  double median_1 = 0.0;
  if (count(v)%2!=0){
    median_1 = v[count(v)/2];
}
else {
int n1 = count(v)/2+1;
int n2 = count(v)/2;
median_1 =(v[n1]+v[n2])/2;
}
return median_1;
}

double mode(vector<double> v) {
sort(v);
double num = v[0];
double mode_1 = num;
int count = 0;
int countMode = 0;
for (int i = 0; i<v.size(); i++)
{
  if (v[i] == num) 
  { 
    ++count;
  }
  if (count > countMode) 
  {
    countMode = count; 
    mode_1 = num;
  }
  count = 0;
  num = v[i];
      
            
}
return mode_1;
}

double min(vector<double> v) {
double min_1 = v[0];
for(int i = 0; i < v.size(); i++)
    {
        if(v[i] < min_1)
            min_1 = v[i];
    }
    return  min_1 ;
}

double max(vector<double> v) {
double max_1 = v[0];
for(int r = 0; r < v.size(); r++)
    {
        if(v[r] > max_1){
          max_1 = v[r];
        }
    }
    return  max_1;
}

double stdev(vector<double> v) {
  double sum_2 = 0.0;
  double m = sum(v)/count(v);
  for(int s=0; s<v.size(); s++){
    sum_2+=(v[s]-m)*(v[s]-m);
  }
return  sqrt(sum_2/(count(v)-1));
}

double percentile(vector<double> v, double p) {
  sort(v);
  double percentile = 0.0;
  double n = 0.0;
  n = p*(count(v) - 1)+1;
  int k = static_cast<int>(n);
  float d = n-k;
  if (p == 1)
  {
    percentile = v[v.size()-1];
  }
  else
  {
    percentile = v[k - 1] + d * (v[k] - v[k - 1]);
  }

  return percentile;
}