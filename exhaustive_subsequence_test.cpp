///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence_test.cpp
//
// Unit tests for exhaustive_subsequence.hpp
//
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "rubrictest.hpp"

#include "exhaustive_subsequence.hpp"

int main() {

  Rubric rubric;

  rubric.criterion("exhaustive_longest_substring trivial cases", 1,
   [&]() {
     TEST_EQUAL("empty-empty", "", exhaustive_longest_substring("", ""));
     TEST_EQUAL("empty-nonempty", "", exhaustive_longest_substring("", "abc"));
     TEST_EQUAL("nonempty-nonempty", "", exhaustive_longest_substring("abc", ""));
     TEST_EQUAL("same string", "abc", exhaustive_longest_substring("abc", "abc"));
   });

   rubric.criterion("exhaustive_longest_substring nontrivial cases", 3,
    [&]() {
      TEST_EQUAL("ababc babca",
                 "babc",
                 exhaustive_longest_substring("ababc", "babca"));
      TEST_EQUAL("hakuna matata",
                 "a",
                 exhaustive_longest_substring("hakuna", "matata"));
      TEST_EQUAL("the rain in spain",
                 "ain",
                 exhaustive_longest_substring("the rain", "in spain"));
      TEST_EQUAL("bottle otter",
                 "ott",
                 exhaustive_longest_substring("bottle", "otter"));
    });

  rubric.criterion("detect_subsequence trivial cases", 1,
   [&]() {
     TEST_TRUE("empty-empty", detect_subsequence("", ""));
     TEST_TRUE("empty-nonempty", detect_subsequence("", "abc"));
     TEST_FALSE("nonempty-empty", detect_subsequence("abc", ""));
     TEST_TRUE("same string", detect_subsequence("abc", "abc"));
   });

   rubric.criterion("detect_subsequence nontrivial cases", 3,
    [&]() {
      TEST_TRUE("empty < abcd", detect_subsequence("", "abcd"));
      TEST_TRUE("a < abcd", detect_subsequence("a", "abcd"));
      TEST_TRUE("b < abcd", detect_subsequence("ab", "abcd"));
      TEST_TRUE("ab < abcd", detect_subsequence("ab", "abcd"));
      TEST_TRUE("c < abcd", detect_subsequence("c", "abcd"));
      TEST_TRUE("ac < abcd", detect_subsequence("ac", "abcd"));
      TEST_TRUE("bc < abcd", detect_subsequence("bc", "abcd"));
      TEST_TRUE("abc < abcd", detect_subsequence("abc", "abcd"));
      TEST_TRUE("d < abcd", detect_subsequence("d", "abcd"));
      TEST_TRUE("ad < abcd", detect_subsequence("ad", "abcd"));
      TEST_TRUE("bd < abcd", detect_subsequence("bc", "abcd"));
      TEST_TRUE("abd < abcd", detect_subsequence("abd", "abcd"));
      TEST_TRUE("cd < abcd", detect_subsequence("cd", "abcd"));
      TEST_TRUE("acd < abcd", detect_subsequence("acd", "abcd"));
      TEST_TRUE("bcd < abcd", detect_subsequence("bcd", "abcd"));
      TEST_TRUE("abcd < abcd", detect_subsequence("abcd", "abcd"));

      TEST_FALSE("aaaa < aaab", detect_subsequence("aaaa", "aaab"));
      TEST_FALSE("aaaa < aaa", detect_subsequence("aaaa", "aaa"));
    });

    rubric.criterion("exhaustive_longest_subsequence", 3,
     [&]() {
       TEST_EQUAL("banana atana",
                  "aana",
                  exhaustive_longest_subsequence("banana", "atana"));
       TEST_EQUAL("banana atana",
                  "aana",
                  exhaustive_longest_subsequence("atana", "banana"));

       TEST_EQUAL("agcat gac",
                  "ga",
                  exhaustive_longest_subsequence("agcat", "gac"));
       TEST_EQUAL("gac agcat",
                  "ga",
                  exhaustive_longest_subsequence("gac", "agcat"));

       TEST_EQUAL("abcdgh aedfhr",
                  "adh",
                  exhaustive_longest_subsequence("abcdgh", "aedfhr"));
       TEST_EQUAL("aedfhr abcdgh",
                  "adh",
                  exhaustive_longest_subsequence("aedfhr", "abcdgh"));

       TEST_EQUAL("aggtab gxtxayb",
                  "gtab",
                  exhaustive_longest_subsequence("aggtab", "gxtxayb"));
       TEST_EQUAL("gxtxayb aggtab",
                  "gtab",
                  exhaustive_longest_subsequence("gxtxayb", "aggtab"));
     });

  return rubric.run();
}
