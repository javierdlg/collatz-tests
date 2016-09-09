// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

/** \file TestCollatz.c++
 * File that runs the tests for the collatz program
 */

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

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(27, 27);
  ASSERT_EQ(112, v);
}

TEST(CollatzFixture, eval_backwards) {
  const int forwards = collatz_eval(4000, 5000);
  const int backwards = collatz_eval(5000, 4000);

  ASSERT_EQ(forwards, backwards);
  ASSERT_EQ(forwards, 215);
  ASSERT_EQ(backwards, 215);
}

TEST(CollatzFixture, eval_large_number) {
  const int v = collatz_eval(971776, 974077);
  ASSERT_EQ(v, 383);
}

TEST(CollatzFixture, eval_one) {
  const int v = collatz_eval(1, 1);
  ASSERT_EQ(v, 1);
}

TEST(CollatzFixture, eval_same_number) {
  const int v = collatz_eval(1000, 1000);
  ASSERT_EQ(v, 112);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
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

TEST(CollatzFixture, solve_backwards) {
  istringstream r_forwards("4000 5000");
  istringstream r_backwards("5000 4000");

  ostringstream w_forwards;
  ostringstream w_backwards;

  collatz_solve(r_forwards, w_forwards);
  collatz_solve(r_backwards, w_backwards);

  ASSERT_EQ("4000 5000 215\n", w_forwards.str());
  ASSERT_EQ("5000 4000 215\n", w_backwards.str());
}
