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
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1000, 900);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(14234, 67);
    ASSERT_EQ(276, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(100, 100);
    ASSERT_EQ(26, v);}

// ----
// calculate
// ----
TEST(CollatzFixture, calculate_1) {
  const int v = collatz_calculate(27);
  ASSERT_EQ(112, v);}

TEST(CollatzFixture, calculate_2) {
  const int v = collatz_calculate(7896);
  ASSERT_EQ(40, v);}

TEST(CollatzFixture, calculate_3) {
  const int v = collatz_calculate(1);
  ASSERT_EQ(1, v);}

// ----
// calculate optimized
// ----
TEST(CollatzFixture, calculate_optimized_1) {
  int range_low = 27;
  int range_high = 7896;
  int range_diff = range_high - range_low;
  vector<int> cache((3 * range_high) + 1);
  const int v = collatz_calculate_optimized(range_low, &cache, range_diff);
  ASSERT_EQ(112, v);}

TEST(CollatzFixture, calculate_optimized_2) {
  int range_low = 27;
  int range_high = 7896;
  int range_diff = range_high - range_low;
  vector<int> cache((3 * range_high) + 1);
  const int v = collatz_calculate_optimized(range_high, &cache, range_diff);
  ASSERT_EQ(40, v);}

TEST(CollatzFixture, calculate_optimized_3) {
  int range_low = 1;
  int range_high = 1;
  int range_diff = range_high - range_low;
  vector<int> cache((3 * range_high) + 1);
  const int v = collatz_calculate_optimized(range_low, &cache, range_diff);
  ASSERT_EQ(1, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
