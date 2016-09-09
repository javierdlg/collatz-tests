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

TEST(CollatzFixture, read_1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("100 200\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(100, i);
  ASSERT_EQ(200, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("201 210\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(201, i);
  ASSERT_EQ(210, j);
}

TEST(CollatzFixture, read_4) {
  istringstream r("900 1000\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(900, i);
  ASSERT_EQ(1000, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(201, 210);
  ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 100, 200, 125);
  ASSERT_EQ("100 200 125\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 201, 210, 89);
  ASSERT_EQ("201 210 89\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 900, 1000, 174);
  ASSERT_EQ("900 1000 174\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("1 100\n10 200\n200 300\n1 300\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 100 119\n10 200 125\n200 300 128\n1 300 128\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("1 1000\n500 1000\n250 750\n250 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1000 179\n500 1000 179\n250 750 171\n250 1000 179\n", w.str());
}

TEST(CollatzFixture, solve_4) {
  istringstream r("1 10000\n5000 10000\n2500 7500\n2500 10000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10000 262\n5000 10000 262\n2500 7500 262\n2500 10000 262\n",
            w.str());
}
