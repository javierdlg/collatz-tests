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

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

//----My Tests----

TEST(CollatzFixture, read1) {
  istringstream r("513 610\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(513, i);
  ASSERT_EQ(610, j);
}

TEST(CollatzFixture, read2) {
  istringstream r("22 114\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(22, i);
  ASSERT_EQ(114, j);
}

TEST(CollatzFixture, read3) {
  istringstream r("8312 12\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(8312, i);
  ASSERT_EQ(12, j);
}

TEST(CollatzFixture, read4) {
  istringstream r("423 922\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(423, i);
  ASSERT_EQ(922, j);
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

//---My Tests---

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(8671, 224);
  ASSERT_EQ(262, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(582, 223);
  ASSERT_EQ(144, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(55192, 5123);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(314, 1521);
  ASSERT_EQ(182, v);
}

//
//-----
// eval_helper
//----

TEST(CollatzFixture, eval_help_1) {
  const int v = eval_helper(321);
  ASSERT_EQ(25, v);
}

TEST(CollatzFixture, eval_help_2) {
  const int v = eval_helper(4412);
  ASSERT_EQ(47, v);
}

TEST(CollatzFixture, eval_help_3) {
  const int v = eval_helper(3221);
  ASSERT_EQ(23, v);
}

TEST(CollatzFixture, eval_help_4) {
  const int v = eval_helper(6);
  ASSERT_EQ(9, v);
}

//-----
// optimized_eval
//----

TEST(CollatzFixture, eval_opt_1) {
  const int v = optimized_eval(0, 1233, 551);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_opt_2) {
  const int v = optimized_eval(0, 5512, 3312);
  ASSERT_EQ(238, v);
}

TEST(CollatzFixture, eval_opt_3) {
  const int v = optimized_eval(0, 15, 10);
  ASSERT_EQ(18, v);
}

TEST(CollatzFixture, eval_opt_4) {
  const int v = optimized_eval(0, 4412, 3315);
  ASSERT_EQ(238, v);
}

//-----
// unoptimized_eval
//----

TEST(CollatzFixture, eval_unopt_1) {
  const int v = un_optimized_eval(0, 1233, 551);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_unopt_2) {
  const int v = un_optimized_eval(0, 5512, 3312);
  ASSERT_EQ(238, v);
}

TEST(CollatzFixture, eval_unopt_3) {
  const int v = un_optimized_eval(0, 15, 10);
  ASSERT_EQ(18, v);
}

TEST(CollatzFixture, eval_unopt_4) {
  const int v = un_optimized_eval(0, 4412, 3315);
  ASSERT_EQ(238, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

//--My Tests----

TEST(CollatzFixture, print1) {
  ostringstream w;
  collatz_print(w, 4412, 3315, 238);
  ASSERT_EQ("4412 3315 238\n", w.str());
}

TEST(CollatzFixture, print2) {
  ostringstream w;
  collatz_print(w, 15, 10, 18);
  ASSERT_EQ("15 10 18\n", w.str());
}

TEST(CollatzFixture, print3) {
  ostringstream w;
  collatz_print(w, 5512, 3312, 238);
  ASSERT_EQ("5512 3312 238\n", w.str());
}

TEST(CollatzFixture, print4) {
  ostringstream w;
  collatz_print(w, 1233, 551, 182);
  ASSERT_EQ("1233 551 182\n", w.str());
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

//--My Tests--

TEST(CollatzFixture, solve1) {
  istringstream r("900 1000\n5819 4668\n1945 3486\n5227 782\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("900 1000 174\n5819 4668 236\n1945 3486 217\n5227 782 238\n",
            w.str());
}

TEST(CollatzFixture, solve2) {
  istringstream r("4140 4397\n5565 2468\n6071 4096\n2378 3579\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("4140 4397 215\n5565 2468 238\n6071 4096 236\n2378 3579 217\n",
            w.str());
}

TEST(CollatzFixture, solve3) {
  istringstream r("2124 6393\n3792 4329\n1472 6562\n1338 3211\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("2124 6393 262\n3792 4329 202\n1472 6562 262\n1338 3211 217\n",
            w.str());
}

TEST(CollatzFixture, solve4) {
  istringstream r("1844 612\n125 4664\n5298 2040\n2334 1703\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1844 612 182\n125 4664 238\n5298 2040 238\n2334 1703 183\n",
            w.str());
}
