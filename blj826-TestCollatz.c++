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
// solution
// ----

TEST(CollatzFixture, solution_1) {
    const int v = collatz_solution(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, solution_2) {
    const int v = collatz_solution(5, 1);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, solution_3) {
    const int v = collatz_solution(2, 1);
    ASSERT_EQ(2, v);}


// ----
// opt
// ----

TEST(CollatzFixture, opt_1) {
    const int v = collatz_opt(1000, 2000, 1);
    ASSERT_EQ(182, v);}

TEST(CollatzFixture, opt_2) {
    const int v = collatz_opt(100, 200, 1);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, opt_3) {
    const int v = collatz_opt(1500, 2500, 1);
    ASSERT_EQ(209, v);}

// ----
// start
// ----

TEST(CollatzFixture, start_1) {
    const int v = collatz_start(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, start_2) {
    const int v = collatz_start(1, 1000);
    ASSERT_EQ(179, v);}

TEST(CollatzFixture, start_3) {
    const int v = collatz_start(1, 1);
    ASSERT_EQ(1, v);}


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
    istringstream r("10 1\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 10, i);
    ASSERT_EQ(1, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("1 5\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(5, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("1 1\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(1, j);}

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
    const int v = collatz_eval(1234, 5678);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(3421, 1234);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}


// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 5, 10, 20);
    ASSERT_EQ("5 10 20\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 120, 32452, 308);
    ASSERT_EQ("120 32452 308\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("5 10\n300 400\n3 4\n200 2000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("5 10 20\n300 400 144\n3 4 8\n200 2000 182\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("1 1\n10 9000\n99 55\n2000 3000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1 1\n10 9000 262\n99 55 119\n2000 3000 217\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("7 9\n30 40\n234 645\n234 535\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("7 9 20\n30 40 107\n234 645 144\n234 535 144\n", w.str());}

