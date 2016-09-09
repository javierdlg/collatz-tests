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
  istringstream r("44 97\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(44, i);
  ASSERT_EQ(97, j);
}

// ----
// compute_algo
// ----
TEST(CollatzFixture, compute_algo_1) {
  const int v = compute_algo(1);
  ASSERT_EQ(1, v);
}
TEST(CollatzFixture, compute_algo_2) {
  const int v = compute_algo(2);
  ASSERT_EQ(2, v);
}
TEST(CollatzFixture, compute_algo_3) {
  const int v = compute_algo(137);
  ASSERT_EQ(91, v);
}
TEST(CollatzFixture, compute_algo_4) {
  const int v = compute_algo(906);
  ASSERT_EQ(16, v);
}
TEST(CollatzFixture, compute_algo_5) {
  const int v = compute_algo(1028);
  ASSERT_EQ(125, v);
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
  collatz_print(w, 900, 1000, 74);
  ASSERT_EQ("900 1000 74\n", w.str());
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
  istringstream r("423 803\n820 857\n676 928\n328 477");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("423 803 171\n820 857 135\n676 928 179\n328 477 134\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("542 625\n23 829\n149 454\n340 371");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("542 625 137\n23 829 171\n149 454 144\n340 371 126\n", w.str());
}