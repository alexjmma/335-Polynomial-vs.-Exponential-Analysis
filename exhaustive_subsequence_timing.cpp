///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence_timing.cpp
//
// Example code showing how to run each algorithm while measuring
// elapsed times precisely. You should modify this program to gather
// all of your experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#include "timer.hpp"

#include "exhaustive_subsequence.hpp"

void print_bar() {
  std::cout << std::string(79, '-') << std::endl;
}

int main() {

  const int n = 20;
  const int subsequence_max_n = 25;

  assert(n > 0);

  std::string a(random_letter_string(1, n, 4)),
              b(random_letter_string(2, n, 4));

  double elapsed;
  Timer timer;

  print_bar();
  std::cout << "n = " << n << std::endl
            << "a='" << a << "'" << std::endl
            << "b='" << b << "'" << std::endl;

  print_bar();
  std::cout << "longest substring" << std::endl;
  timer.reset();
  auto substring = exhaustive_longest_substring(a, b);
  elapsed = timer.elapsed();
  std::cout << "longest substring='" << substring << "'"
            << " of length=" << substring.size() << std::endl;
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();
  std::cout << "longest subsequence" << std::endl;
  if (n > subsequence_max_n) {
    std::cout << "(n too big, skipping)" << std::endl;
  } else {
    timer.reset();
    auto subsequence = exhaustive_longest_subsequence(a, b);
    elapsed = timer.elapsed();
    std::cout << "longest subsequence='" << subsequence << "'"
              << " of length=" << subsequence.size() << std::endl;
    std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;
  }

  print_bar();

  return 0;
}
