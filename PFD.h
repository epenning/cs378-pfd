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
#include <vector>     // vector
#include <list>       // list
#include <queue>      // queue
#include <functional> // greater

using namespace std;

// ------------
// pfd_read_first
// ------------

/**
 * read the two first ints of input
 * @param s a string
 * @return a pair of ints, representing the number of tasks and number of rules
 */
pair<int, int> pfd_read_first (const string& s);

// ------------
// pfd_read
// ------------

/**
 * read a string of multiple ints
 * @param s a string
 * @return a vector, with first element being the task and the others being those it is dependent on
 */
vector<int> pfd_read (const string& s);


// -----------
// make_lists
// -----------

/**
 * initialize empty adjacenty lists for the number of tasks
 * @param dimension the number of tasks
 * @return the empty adjacency lists graph structure
 */
vector<list<int>> make_lists (int dimension);

// ------------
// set_list
// ------------

/**
 * put a task into the list of successors for each predecessor listed
 * @param v first element: the task to be added to each successor list
 *          other elements: the predecessors onto whose lists the task will be added
 * @return the updated adjacency lists graph structure
 */
vector<list<int>> set_list (vector<int> v);

// ------------
// make_graph
// ------------

/**
 * create an adjacency list graph structure from an input stream
 * @param r an istream
 * @return the fully populated adjacency lists graph structure
 */
vector<list<int>> make_graph (istream& r);

// ------------
// task_independent
// ------------

/**
 * check if a task has any predecessors or not in graph
 * @param graph the adjacency list representation of the graph of tasks
 * @param task the task to check for dependency
 * @return true if task has no predecessors, otherwise false
 */
bool task_independent (vector<list<int>> graph, int task);

// ------------
// pfd_eval
// ------------

/**
 * produce an ordering for the task dependencies problem
 * @param graph the adjacency list representation of the graph of tasks
 * @return an ordered list of the tasks following the dependency rules
 */
list<int> pfd_eval (vector<list<int>> graph);

// -------------
// pfd_print
// -------------

/**
 * print a vector of ints (tasks)
 * @param w an ostream
 * @param v the vector
 * @param num_task the number of tasks to be printed
 */
void pfd_print (ostream& w, vector<int> v, int num_task);

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
