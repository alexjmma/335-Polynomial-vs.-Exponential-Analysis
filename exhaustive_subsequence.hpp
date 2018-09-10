///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence.hpp
//
// Exhaustive search algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>

std::string exhaustive_longest_substring(const std::string& a,
                                         const std::string& b) {
  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function.
  std::string best = "";
  std::size_t found = 0;
  int n = a.length();

  for(int i = 0; i < n; i++){
    for(int k = n; k > 0; k--){
      std::string temp = a.substr(i, k);
      found = b.find(temp);
      int t = temp.length();
      int blen = best.length();
      if ((found != std::string::npos) && (t > blen)){
        best = temp;
      }
    }
  }

  return best;
  }

std::string random_letter_string(int seed, int size, int distinct_letters) {

  assert(size >= 0);
  assert(distinct_letters > 0);
  assert(distinct_letters <= 26);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist('a', 'a' + distinct_letters - 1);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {
// TODO: replace this comment, and bogus return statement, with an actual
// implementation of the function.
int n = candidate_subsequence.length();
int m = candidate_supersequence.length();
int left = 0; //leftover characters for subsequence

if (n > m) {
  return false;
}
else if (candidate_subsequence.empty()){
  return true;
}
else if (candidate_supersequence.empty()){
  return false;
}

for (int i = 0; i < n; i++) {
  for (int k = i; k < m; k++)
  {
    if (candidate_subsequence[i] == candidate_supersequence[k]) {
      i++;
    }
  }
  left = n - i;

  if (left > 0)
  {
    return false;
  }
}

return true;
}

std::string exhaustive_longest_subsequence(const std::string& a,
                                           const std::string& b) {
// TODO: replace this comment, and bogus return statement, with an actual
// implementation of the function.
std::string shorter = "";
std::string longer = "";
std::string best = "";
std::string temp = "";
int n = a.length();
int m = b.length();

if ((n < m) || (n == m)) {
  shorter = a;
  longer = b;
}
else
{
  shorter = b;
  longer = a;
}

std::vector<std::string> subs;

int s = shorter.length();
for (int j = 0; j < (int)pow(2, s); j++) {
  for (int k = 0; k < n; k++) {
    if (((j >> k) & 1) == 1) {

      temp += shorter[k];
    }
  }
  int t = temp.length();
  int b = best.length();
  if (find(subs.begin(), subs.end(), temp) == subs.end()) {
    if (detect_subsequence(temp, longer) && (t > b)) {
      best = temp;
    }
    subs.push_back(temp);
  }
  temp = "";
}

return best;
}
