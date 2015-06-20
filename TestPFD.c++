// --------------------------------
// projects/pfd/TestPFD.c++
// Copyright (C) 2015
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
#include <vector>
#include <list>

#include "gtest/gtest.h"

#include "PFD.h"

using namespace std;

// -----------
// TestPFD
// -----------

// ----
// read_first
// ----

TEST(PFDFixture, read_first) {
    string s = "5 4\n";
    const pair<int, int> p = pfd_read_first(s);
    ASSERT_EQ( 5, p.first);
    ASSERT_EQ(4, p.second);
	}

// ----
// read
// ----

TEST(PFDFixture, read) {
    string s = "3 2 1 5\n";
    std::vector<int> p = pfd_read(s);
    ASSERT_EQ( 3, p[0]);
    ASSERT_EQ( 1, p[1]);
    ASSERT_EQ( 5, p[2]);
	}

// ----
// make_lists
// ----

TEST(PFDFixture, make_lists) {
    std::vector<list<int>> lists = make_lists(5);
    ASSERT_EQ( 5, lists.size());
	}

// ----
// set_lists
// ----

TEST(PFDFixture, set_lists_1) {
    make_lists(5);
    std::vector<list<int>> lists = set_list({ 3, 1, 5 });
    ASSERT_EQ( 2, lists[3].size());
	}

TEST(PFDFixture, set_lists_2) {
    make_lists(5);
    auto lists = set_list({ 3, 1, 5 });
    auto iter = lists[3].begin();
    ASSERT_EQ( 1, *(iter++));
    ASSERT_EQ( 5, *(iter++));
	}

// ----
// make_graph
// ----

TEST(PFDFixture, make_graph_1) {
    istringstream r("5 1\n3 2 1 5\n");
    auto lists = make_graph(r);
    ASSERT_EQ( 5, lists.size());
    auto iter = lists[3].begin();
    ASSERT_EQ( 1, *(iter++));
    ASSERT_EQ( 5, *(iter++));
	}

// ----
// eval
// ----

TEST(PFDFixture, eval_1) {
    // FIX THIS
	}

// -----
// print
// -----

TEST(PFDFixture, print) {
    ostringstream w;
    pfd_print(w, {1, 5, 3, 2, 4}, 5);
    ASSERT_EQ("1 5 3 2 4 \n", w.str());
	}

// -----
// solve
// -----
/*
TEST(PFDFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    pfd_solve(r, w);
    ASSERT_EQ("1 10 1\n100 200 1\n201 210 1\n900 1000 1\n", w.str());
	}*/

/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall PFD.c++ TestPFD.c++ -o TestPFD -lgtest -lgtest_main -lpthread



% valgrind TestPFD        >  TestPFD.out 2>&1
% gcov-4.8 -b PFD.c++     >> TestPFD.out
% gcov-4.8 -b TestPFD.c++ >> TestPFD.out



% cat TestPFD.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestPFD
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from PFD
[ RUN      ] PFD.read
[       OK ] PFD.read (31 ms)
[ RUN      ] PFD.eval_1
[       OK ] PFD.eval_1 (5 ms)
[ RUN      ] PFD.eval_2
[       OK ] PFD.eval_2 (3 ms)
[ RUN      ] PFD.eval_3
[       OK ] PFD.eval_3 (3 ms)
[ RUN      ] PFD.eval_4
[       OK ] PFD.eval_4 (3 ms)
[ RUN      ] PFD.print
[       OK ] PFD.print (17 ms)
[ RUN      ] PFD.solve
[       OK ] PFD.solve (10 ms)
[----------] 7 tests from PFD (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'PFD.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'PFD.c++.gcov'
...
File 'TestPFD.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestPFD.c++.gcov'
...
*/
