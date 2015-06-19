// --------------------------
// projects/pfd/PFD.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>
#include <list>

using namespace std;

// ------------
// pfd_read_first
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the number of tasks and number of rules
 */
pair<int, int> pfd_read_first (const string& s);

// ------------
// pfd_read
// ------------

/**
 * read a string of ints
 * @param s a string
 * @return a vector, with first element being the task and the others being those it is dependent on
 */
std::vector<int> pfd_read (const string& s);
    // FIX THIS


// -----------
// make_lists
// -----------

/**
 * initialize the adjacenty lists to the number of tasks
 * @param dimension the number of tasks
 */
vector<list<int>> make_lists (int dimension);

// ------------
// set_list
// ------------

vector<list<int>> set_list (vector<int> v);

// ------------
// make_graph
// ------------

vector<list<int>> make_graph (istream& r, ostream& w);

// ------------
// pfd_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int pfd_eval (int i, int j);
    // FIX THIS

// -------------
// pfd_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void pfd_print (ostream& w, int i, int j, int v);
    // FIX THIS

// -------------
// pfd_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void pfd_solve (istream& r, ostream& w);
    // FIX THIS

#endif // PFD_h
