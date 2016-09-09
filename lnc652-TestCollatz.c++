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

// Downing's Tests
TEST(CollatzFixture, read_1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// My tests
TEST(CollatzFixture, read_2) {
  istringstream r("10 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(10, i);
  ASSERT_EQ(1, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("999999 999999\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(999999, i);
  ASSERT_EQ(999999, j);
}

// ----
// eval
// ----

// Downing's Tests
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

// My tests
TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(413, 612);
  ASSERT_EQ(142, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(17, 17);
  ASSERT_EQ(13, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(200, 100);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(113382, 1);
  ASSERT_EQ(354, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(83084, 97878);
  ASSERT_EQ(333, v);
}
// -----
// length
// -----

// My tests
TEST(CollatzFixture, len_1) {
  const int v = collatz_length(413);
  ASSERT_EQ(90, v);
}

TEST(CollatzFixture, len_2) {
  const int v = collatz_length(226611);
  ASSERT_EQ(63, v);
}

TEST(CollatzFixture, len_3) {
  const int v = collatz_length(7806);
  ASSERT_EQ(177, v);
}

// -----
// print
// -----

// Downing's Tests
TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

// My tests
TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 10, 1, 20);
  ASSERT_EQ("10 1 20\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 999999, 999999, 259);
  ASSERT_EQ("999999 999999 259\n", w.str());
}

// -----
// solve
// -----

// Downing's Tests
TEST(CollatzFixture, solve_1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

// My tests
TEST(CollatzFixture, solve_2) {
  istringstream r("10 1\n200 100\n210 201\n1000 900\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("413 612\n612 413\n999999 999999\n83084 97878\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("413 612 142\n612 413 142\n999999 999999 259\n83084 97878 333\n",
            w.str());
}
