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
#include <utility>  // pair

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
  istringstream r("10 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(10, i);
  ASSERT_EQ(1, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("0 0\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(0, i);
  ASSERT_EQ(0, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(200, 100);
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

// ----
// cycle
// ----

TEST(CollatzFixture, cycle_1) {
  const int v = collatz_cycle(10);
  ASSERT_EQ(7, v);
}

TEST(CollatzFixture, cycle_2) {
  const int v = collatz_cycle(201);
  ASSERT_EQ(19, v);
}

TEST(CollatzFixture, cycle_3) {
  const int v = collatz_cycle(1000);
  ASSERT_EQ(112, v);
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
  collatz_print(w, -10, 0, 50);
  ASSERT_EQ("-10 0 50\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 111, 111, 111);
  ASSERT_EQ("111 111 111\n", w.str());
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
  istringstream r("10 1\n200 100\n210 201\n1000 900\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("860500 860080\n806280 806280\n10 10\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("860500 860080 357\n806280 806280 70\n10 10 7\n", w.str());
}

/*
% g++-4.8 -pedantic -std=c++11 -Wall -fprofile-arcs -ftest-coverage Collatz.c++
TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -pthread
% valgrind ./TestCollatz                                           >
TestCollatz.tmp 2>&1
% gcov-4.8 -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >>
TestCollatz.tmp
% gcov-4.8 -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >>
TestCollatz.tmp
*/
