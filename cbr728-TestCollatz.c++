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

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("5 20\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(5, i);
  ASSERT_EQ(20, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("100 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(100, i);
  ASSERT_EQ(1, j);
}

// ----
// collatz_single
// ----

TEST(CollatzFixture, collatz_single_1) {
  const int v = collatz_single(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, collatz_single_2) {
  const int v = collatz_single(7);
  ASSERT_EQ(17, v);
}

TEST(CollatzFixture, collatz_single_3) {
  const int v = collatz_single(10);
  ASSERT_EQ(7, v);
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

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 10, 20, 30);
  ASSERT_EQ("10 20 30\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 5, 1, 40);
  ASSERT_EQ("5 1 40\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("1001 5\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1001 5 179\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("22034 80317\n62499 591\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("22034 80317 351\n62499 591 340\n", w.str());
}
