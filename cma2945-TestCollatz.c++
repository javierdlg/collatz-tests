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
  istringstream r("5 222\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(5, i);
  ASSERT_EQ(222, j);
}

#ifdef OPTIMIZATION
// ----
// find_cycle_length_op
// ----
TEST(CollatzFixture, cycle_length_op_1) {
  const int l = find_cycle_length_op(10);
  ASSERT_EQ(7, l);
}

TEST(CollatzFixture, cycle_length_op_2) {
  const int l = find_cycle_length_op(123456);
  ASSERT_EQ(62, l);
}

TEST(CollatzFixture, cycle_length_op_3) {
  const int l = find_cycle_length_op(999999);
  ASSERT_EQ(259, l);
}

#else
// ----
// cycle_length
// ----

TEST(CollatzFixture, cycle_length_1) {
  const int l = find_cycle_length(1);
  ASSERT_EQ(1, l);
}

TEST(CollatzFixture, cycle_length_2) {
  const int l = find_cycle_length(9544);
  ASSERT_EQ(105, l);
}

TEST(CollatzFixture, cycle_length_3) {
  const int l = find_cycle_length(999999);
  ASSERT_EQ(259, l);
}
#endif

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
  collatz_print(w, 5, 5, 6);
  ASSERT_EQ("5 5 6\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 100, 111, 114);
  ASSERT_EQ("100 111 114\n", w.str());
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
  istringstream r("14 66\n100 111\n3920 291\n10184 199\n12 99\n2098 12\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("14 66 113\n100 111 114\n3920 291 238\n10184 199 262\n12 99 "
            "119\n2098 12 182\n",
            w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("1 1\n2 2\n3 3\n4 4\n5 5\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1 1\n2 2 2\n3 3 8\n4 4 3\n5 5 6\n", w.str());
}