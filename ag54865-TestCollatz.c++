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
    const int v = collatz_eval(1, 500);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_6_Reverse) {
    const int v = collatz_eval(500, 1);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_7_Same) {
    const int v = collatz_eval(67433, 67433);
    ASSERT_EQ(69, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(171, 171);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(108, 108);
    ASSERT_EQ(114, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(32, 57);
    ASSERT_EQ(113, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(53, 98);
    ASSERT_EQ(119, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(90, 91);
    ASSERT_EQ(93, v);}


// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 10, 1, 20);
    ASSERT_EQ("10 1 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 67433, 67433, 69);
    ASSERT_EQ("67433 67433 69\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 32, 57, 113);
    ASSERT_EQ("32 57 113\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("67433 67433\n45 47\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("67433 67433 69\n45 47 105\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("32 57\n53 98\n4 8\n90 91\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("32 57 113\n53 98 119\n4 8 17\n90 91 93\n", w.str());}
