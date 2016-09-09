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
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("100 200\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(100, i);
    ASSERT_EQ(200, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("201 210\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(201, i);
    ASSERT_EQ(210, j);}

// --------------
// collatz helper
// --------------

TEST(CollatzFixture, collatz_helper_1) {
    const int v = collatz_helper(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, collatz_helper_2) {
    const int v = collatz_helper(5);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, collatz_helper_3) {
    const int v = collatz_helper(10);
    ASSERT_EQ(7, v);}

// ------------------------
// collatz helper optimized
// ------------------------

TEST(CollatzFixture, collatz_helper_optimized_1) {
    const int v = collatz_helper_optimized(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, collatz_helper_optimized_2) {
    const int v = collatz_helper_optimized(5);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, collatz_helper_optimized_3) {
    const int v = collatz_helper_optimized(10);
    ASSERT_EQ(7, v);}

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

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("111901 112708\n603358 603652\n351208 354794\n150029 150610\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("111901 112708 323\n603358 603652 266\n351208 354794 379\n150029 150610 339\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("850891 851024\n869495 869868\n937964 938478\n508310 509548\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("850891 851024 357\n869495 869868 357\n937964 938478 445\n508310 509548 377\n", w.str());}