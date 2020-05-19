#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

template<typename T0>
int timer(T0 func) {
  auto start = high_resolution_clock::now();
  func();
  auto stop = high_resolution_clock::now();
  int duration =  duration_cast<microseconds>(stop-start).count();
  return duration;
}

int foo() {
  cout << "hello";
  return 2;
}

int main() {
  int (*bar)() = foo;

  int test = timer(bar);
  cout << test;
}
