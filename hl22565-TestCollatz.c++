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
    const int v = collatz_eval(540, 3426);
    ASSERT_EQ(217, v);}
TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(336, 6505);
    ASSERT_EQ(262, v);}
TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(4443, 5763);
    ASSERT_EQ(236, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 336, 6505, 262);
    ASSERT_EQ("336 6505 262\n", w.str());}
TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 540, 3426, 217);
    ASSERT_EQ("540 3426 217\n", w.str());}
TEST(CollatzFixture, print_5) {
    ostringstream w;
    collatz_print(w, 201, 210, 89);
    ASSERT_EQ("201 210 89\n", w.str());}
TEST(CollatzFixture, print_6) {
    ostringstream w;
    collatz_print(w, 4443, 5763, 236);
    ASSERT_EQ("4443 5763 236\n", w.str());}
// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
