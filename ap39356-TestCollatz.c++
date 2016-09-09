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

TEST(CollatzFixture, read1) {
istringstream r("1 10\n");
int           i;
int           j;
const bool b = collatz_read(r, i, j);
ASSERT_TRUE(b);
ASSERT_EQ( 1, i);
ASSERT_EQ(10, j);}

TEST(CollatzFixture, read2) {
istringstream r("1 1\n");
int           i;
int           j;
const bool b = collatz_read(r, i, j);
ASSERT_TRUE(b);
ASSERT_EQ( 1, i);
ASSERT_EQ( 1, j);}

TEST(CollatzFixture, read3) {
istringstream r("99 100\n");
int           i;
int           j;
const bool b = collatz_read(r, i, j);
ASSERT_TRUE(b);
ASSERT_EQ( 99, i);
ASSERT_EQ(100, j);}

TEST(CollatzFixture, read4) {
istringstream r("55 99\n");
int           i;
int           j;
const bool b = collatz_read(r, i, j);
ASSERT_TRUE(b);
ASSERT_EQ(55, i);
ASSERT_EQ(99, j);}

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
const int v = collatz_eval(55, 99);
ASSERT_EQ(119, v);}

TEST(CollatzFixture, eval_6) {
const int v = collatz_eval(901, 1001);
ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_7) {
const int v = collatz_eval(129, 296);
ASSERT_EQ(128, v);}

// -----
// print
// -----

TEST(CollatzFixture, print1) {
ostringstream w;
collatz_print(w, 1, 10, 20);
ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print2) {
ostringstream w;
collatz_print(w, 1, 1, 1);
ASSERT_EQ("1 1 1\n", w.str());}

TEST(CollatzFixture, print3) {
ostringstream w;
collatz_print(w, 55, 99, 119);
ASSERT_EQ("55 99 119\n", w.str());}

TEST(CollatzFixture, print4) {
ostringstream w;
collatz_print(w, 900, 1000, 174);
ASSERT_EQ("900 1000 174\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve1) {
istringstream r("1 10\n100 200\n201 210\n900 1000\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve2) {
istringstream r("1 1\n100 200\n201 210\n900 1000\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("1 1 1\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve3) {
istringstream r("200 300\n300 400\n400 500\n500 600\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("200 300 128\n300 400 144\n400 500 142\n500 600 137\n", w.str());}

TEST(CollatzFixture, solve4) {
istringstream r("44 55\n100 101\n399 499\n100 700\n");
ostringstream w;
collatz_solve(r, w);
ASSERT_EQ("44 55 113\n100 101 26\n399 499 142\n100 700 145\n", w.str());}