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

TEST(CollatzFixture, read2) {
  istringstream r("13044 45122 \n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(13044, i);
  ASSERT_EQ(45122, j);
}

TEST(CollatzFixture, read3) {
  istringstream r("102765 100783\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(102765, i);
  ASSERT_EQ(100783, j);
}

TEST(CollatzFixture, read4) {
  istringstream r("59692 9213\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(59692, i);
  ASSERT_EQ(9213, j);
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
  const int v = collatz_eval(13044, 45122);
  ASSERT_EQ(324, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(102765, 100783);
  ASSERT_EQ(310, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(59692, 9213);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(49426, 42807);
  ASSERT_EQ(314, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print2) {
  ostringstream w;
  collatz_print(w, 13044, 45122, 324);
  ASSERT_EQ("13044 45122 324\n", w.str());
}

TEST(CollatzFixture, print3) {
  ostringstream w;
  collatz_print(w, 7605, 33244, 308);
  ASSERT_EQ("7605 33244 308\n", w.str());
}

TEST(CollatzFixture, print4) {
  ostringstream w;
  collatz_print(w, 102765, 100783, 310);
  ASSERT_EQ("102765 100783 310\n", w.str());
}

TEST(CollatzFixture, print5) {
  ostringstream w;
  collatz_print(w, 59692, 9213, 340);
  ASSERT_EQ("59692 9213 340\n", w.str());
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

TEST(CollatzFixture, solve2) {
  istringstream r(
      "13044 45122\n102765 100783\n59692 9213\n49426 42807\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("13044 45122 324\n102765 100783 310\n59692 9213 340\n49426 42807 314\n",
            w.str());
}

TEST(CollatzFixture, solve3) {
  istringstream r(
      "7605 33244\n1831 6985\n74659 67428\n89667 33698\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("7605 33244 308\n1831 6985 262\n74659 67428 325\n89667 33698 351\n",
            w.str());
}
