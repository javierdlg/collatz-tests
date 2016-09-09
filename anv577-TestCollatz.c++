// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_4) {
  istringstream r("888 9999\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(888, i);
  ASSERT_EQ(9999, j);
}

TEST(CollatzFixture, read_5) {
  istringstream r("75502 5151\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(75502, i);
  ASSERT_EQ(5151, j);
}

TEST(CollatzFixture, read_6) {
  istringstream r("315011 989873\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(315011, i);
  ASSERT_EQ(989873, j);
}
// ----
// eval
// ----

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(71101, 96673);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(500, 1000);
  ASSERT_EQ(179, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 25907, 82223, 351);
  ASSERT_EQ("25907 82223 351\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 838316, 839677, 388);
  ASSERT_EQ("838316 839677 388\n", w.str());
}

TEST(CollatzFixture, print_6) {
  ostringstream w;
  collatz_print(w, 45192, 39491, 314);
  ASSERT_EQ("45192 39491 314\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_4) {
  istringstream r("300142 301228\n301701 300441\n500263 500282\n502135 "
                  "502758\n501892 501029\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("300142 301228 340\n301701 300441 340\n500263 500282 364\n502135 "
            "502758 426\n501892 501029 320\n",
            w.str());
}

TEST(CollatzFixture, solve_5) {
  istringstream r("28917 73784\n34540 77120\n95927 61880\n3 12627\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("28917 73784 340\n34540 77120 351\n95927 61880 351\n3 12627 268\n",
            w.str());
}

TEST(CollatzFixture, solve_6) {
  istringstream r("22182 42782\n4020 68682\n90826 40197\n6367 48898\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ(
      "22182 42782 324\n4020 68682 340\n90826 40197 351\n6367 48898 324\n",
      w.str());
}
