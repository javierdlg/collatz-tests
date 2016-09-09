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
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(200, 100);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(210, 201);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(1000, 900);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(20, 20);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(999, 9999);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(5000, 9999);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(340, 3000);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(3000, 340);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_14) {
    const int v = collatz_eval(500, 101);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_15) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_16) {
    const int v = collatz_eval(9999, 9998);
    ASSERT_EQ(92, v);}


// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    const int v = collatz_solve(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, solve_2) {
    const int v = collatz_solve(2);
    ASSERT_EQ(2, v);}

TEST(CollatzFixture, solve_3) {
    const int v = collatz_solve(3);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, solve_4) {
    const int v = collatz_solve(4);
    ASSERT_EQ(3, v);}

TEST(CollatzFixture, solve_5) {
    const int v = collatz_solve(5);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, solve_6) {
    const int v = collatz_solve(6);
    ASSERT_EQ(9, v);}

TEST(CollatzFixture, solve_7) {
    const int v = collatz_solve(7);
    ASSERT_EQ(17, v);}

TEST(CollatzFixture, solve_8) {
    const int v = collatz_solve(8);
    ASSERT_EQ(4, v);}

TEST(CollatzFixture, solve_9) {
    const int v = collatz_solve(9);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, solve_10) {
    const int v = collatz_solve(10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, solve_11) {
    const int v = collatz_solve(10000);
    ASSERT_EQ(30, v);}

TEST(CollatzFixture, solve_12) {
    const int v = collatz_solve(15000);
    ASSERT_EQ(178, v);}

TEST(CollatzFixture, solve_13) {
    const int v = collatz_solve(14985);
    ASSERT_EQ(64, v);}



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
