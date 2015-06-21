// ----------------------------
// projects/pfd/PFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

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
    adj_lists.resize(dimension);
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
    assert(v.size() > 1);
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
// task_independent
// ------------

bool task_independent (vector<list<int>> graph, int task) {
    assert(task <= graph.size());
    for (auto list : graph)
        for (int successor : list)
            if (successor == task)
                return false;
    return true;
}

// ------------
// pfd_eval
// ------------

vector<int> pfd_eval (vector<list<int>> graph) {
    vector<int> solution = {};
    // populate queue of tasks without predecessors
    priority_queue<int, vector<int>, greater<int>> independent_tasks {};
    for (int task = 1; task <= graph.size(); ++task) {
        if (task_independent(graph, task))
            independent_tasks.push(task);
    }

    // extract tasks from graph until all tasks have been listed
    assert(!independent_tasks.empty());
    do {
        // remove independent task from graph
        int task = independent_tasks.top();
        independent_tasks.pop();
        // add task to end of solution
        solution.push_back(task);
        // remove edges to successors from task
        list<int>& successors = graph[task-1];
        while (!successors.empty()) {
            int successor = successors.front();
            successors.pop_front();
            // if removed successor has no other predecessors, add to queue
            if (task_independent(graph, successor))
                independent_tasks.push(successor);
        }
    } while(!independent_tasks.empty());
    assert(solution.size() == graph.size());
    return solution;
}

// -------------
// pfd_print
// -------------

void pfd_print (ostream& w, vector<int> v, int num_task) {
    assert(num_task == v.size());
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
    auto graph = make_graph(r);
    auto solution = pfd_eval(graph);
    pfd_print(w, solution, graph.size());
}

// ----
// main
// ----

int main () {
    using namespace std;
    pfd_solve(cin, cout);
    return 0;
}