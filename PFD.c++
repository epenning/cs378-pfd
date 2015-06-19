// ----------------------------
// projects/pfd/PFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "PFD.h"

using namespace std;

// ------------
// pfd_read
// ------------

pair<int, int> pfd_read (const string& s) {
    // FIX THIS
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// pfd_eval
// ------------

int pfd_eval (int i, int j) {
    // <your code>
    return 1;}

// -------------
// pfd_print
// -------------

void pfd_print (ostream& w, int i, int j, int v) {
    // FIX THIS
    w << i << " " << j << " " << v << endl;}

// -------------
// pfd_solve
// -------------

void pfd_solve (istream& r, ostream& w) {
    // FIX THIS
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = pfd_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = pfd_eval(i, j);
        pfd_print(w, i, j, v);}}
