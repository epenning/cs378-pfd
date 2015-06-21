// ----------------------------
// projects/pfd/PFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>    // assert
#include <iostream>   // endl, istream, ostream
#include <sstream>    // istringstream
#include <string>     // getline, string
#include <utility>    // make_pair, pair
#include <vector>     // vector
#include <list>       // list
#include <queue>      // queue
#include <functional> // greater

#include "PFD.h"

using namespace std;

/**
 * A vector of lists, where the index into vector represents
 * a task (which is task index+1) and the list at that index
 * represents the other tasks which depend on it (successors).
 */
vector<list<int>> adj_lists; 

// ------------
// pfd_read_first
// ------------

pair<int, int> pfd_read_first (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);
}

// ------------
// pfd_read
// ------------

vector<int> pfd_read (const string& s) {
    
    vector<int> v;
    istringstream sin(s);
    int task;
    int num_rules;
    sin >> task;
    sin >> num_rules;
    v.push_back(task);

    int predecessor;
    for (int i = 0; i < num_rules; ++i) {
        sin >> predecessor;
        v.push_back(predecessor);
    }

    return v;
}

// ------------
// make_lists
// ------------

vector<list<int>> make_lists (int dimension) {
    adj_lists.resize(dimension, list<int>(0, 0));
    for (int i = 0; i < dimension; ++i)
    {
        adj_lists[i] = list<int>(0, 0);
    }
    return adj_lists;
}

// ------------
// set_list
// ------------

vector<list<int>> set_list (vector<int> v) {
    // for every listed predecessor, add task to its successor list
    int task = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        (adj_lists[v[i]-1]).push_back(task);
    }
    return adj_lists;
}

// ------------
// make_graph
// ------------

vector<list<int>> make_graph (istream& r) {
    string s;
    // read and use info from the first line
    getline(r, s);
    const pair<int, int> p = pfd_read_first(s);
    make_lists(p.first);
    // read and use info from the remaining lines
    for (int i = 0; i < p.second; ++i)
    {
        getline(r, s);
        vector<int> v = pfd_read(s);
        set_list(v);
    }
    return adj_lists;
}

// ------------
// pfd_eval
// ------------

list<int> pfd_eval (vector<list<int>> graph) {
    /*  ALGORITHM TO USE:
    L ? Empty list that will contain the sorted elements
    S ? Set of all nodes with no incoming edges
    while S is non-empty do
        remove a node n from S
        add n to tail of L
        for each node m with an edge e from n to m do
            remove edge e from the graph
            if m has no other incoming edges then
                insert m into S
    if graph has edges then
        return error (graph has at least one cycle)
    else 
        return L (a topologically sorted order)
    */
    list<int> solution = {};
    priority_queue<int, vector<int>, greater<int>> independent_tasks = {};
    return list<int>(0, 0);}

// -------------
// pfd_print
// -------------

void pfd_print (ostream& w, vector<int> v, int num_task) {
    for (int i = 0; i < num_task-1; ++i)
    {
        w << v[i] << " ";
    }
    w << v[num_task-1] << endl;
}
// -------------
// pfd_solve
// -------------

void pfd_solve (istream& r, ostream& w) {
    // FIX THIS
    /*
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = pfd_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = pfd_eval(i, j);
        pfd_print(w, i, j, v);}
        */}

