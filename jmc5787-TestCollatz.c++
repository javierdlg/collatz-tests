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
    istringstream r("5637 3351\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 5637, i);
    ASSERT_EQ(3351, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("37 9009\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 37, i);
    ASSERT_EQ(9009, j);}

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

// add more tests
TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(5, 5);
    ASSERT_EQ(6, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(394, 934);
    ASSERT_EQ(179, v);}


TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 11338);
    ASSERT_EQ(268, v);}

    
TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(85034, 21);
    ASSERT_EQ(351, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 5317, 1, 84);
    ASSERT_EQ("5317 1 84\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 2563, 89014, 5274);
    ASSERT_EQ("2563 89014 5274\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("7427 39356\n9595 54062\n67371 42578\n92585 76990\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("7427 39356 324\n9595 54062 340\n67371 42578 340\n92585 76990 351\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("22615 53318\n12615 3533\n76524 31085\n18213 33602\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("22615 53318 340\n12615 3533 268\n76524 31085 340\n18213 33602 308\n", w.str());}

TEST(CollatzFixture, solve_42) {
    istringstream r("812 813\n910 911\n837 838\n862 863\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("812 813 42\n910 911 42\n837 838 42\n862 863 42\n", w.str());}
