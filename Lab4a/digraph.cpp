/*********************************************
* file:	~\tnd004\lab\lab4a\digraph.cpp       *
* remark: mplementation of directed graphs   *
* file for students                          *
**********************************************/


#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "digraph.h"
#include "queue.h"

const int INFINITY = 9999;

// -- CONSTRUCTORS

Digraph::Digraph(int n)
{
    assert(n >= 1);
    array = new List[n + 1];
    dist  = new int [n + 1];
    path  = new int [n + 1];
    done  = new bool[n + 1];
    size  = n;
}

// -- DESTRUCTOR

Digraph::~Digraph()
{
    delete[] array;
    delete[] dist;
    delete[] path;
    delete[] done;
}

// -- MEMBER FUNCTIONS

// insert directed edge (u, v) with weight w
// update weight w if edge (u, v) is present
void Digraph::insertEdge(int u, int v, int w)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].insert(v, w);
}

// remove directed edge (u, v)
void Digraph::removeEdge(int u, int v)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].remove(v);
}

// unweighted single source shortest paths
void Digraph::uwsssp(int s)
{
    if (s < 1 || s > size)
    {
         cout << "\nERROR: expected source s in range 1.." << size << " !" << endl;
         return;
    }
    // *** TODO ***
    //use a queue to put unvisited vertices in
    Queue<int> Q;
    for(int i = 0; i < size+1; i++)
    {
        dist[i] = INFINITY;
        path[i] = 0;
        done[i] = false;
    }
    //mark the source
    dist[s] = 0;
    //enqueue the source
    Q.enqueue(s);
    //while Q is not empty
    while(!Q.isEmpty())
    {
        //get first in Q
        int v = Q.getFront();
        Q.dequeue();
        //do something with v?
        Node* temp = array[v].getFirst();
        while(temp)
        {
            if(dist[temp->vertex] == INFINITY)
            {
                path[temp->vertex] = v;
                dist[temp->vertex] = dist[v] + 1;
                Q.enqueue(temp->vertex);
                temp = array[v].getNext();
            }
            else
            {
                temp = array[v].getNext();
            }
        }
        done[v] = true;
    }

}

// positive weighted single source shortest pats
void Digraph::pwsssp(int s)
{
    if (s < 1 || s > size)
    {
         cout << "\nERROR: expected source s in range 1.." << size << " !" << endl;
         return;
    }
    // *** TODO ***
    for(int i = 0; i < size+1; i++)
    {
        dist[i] = INFINITY;
        path[i] = 0;
        done[i] = false;
    }

    dist[s] = 0;
    done[s] = true;
    int v = s;

    while(true)
    {
        Node *temp = array[v].getFirst();
        while(temp)
        {
            if(!done[temp->vertex] && (dist[v] + temp->weight) < dist[temp->vertex])
            {
                    dist[temp->vertex] = dist[v] + temp->weight;
                    path[temp->vertex] = v;
                    temp = array[v].getNext();
            }
            else
            {
                temp = array[v].getNext();
            }
        }

        v = find_smallest_undone();
        if(v == INFINITY)
        {
            break;
        }
        done[v] = true;
    }
}

int Digraph::find_smallest_undone()
{
    int smallest = INFINITY;
    int vertex = INFINITY;
    for(int i = 0; i < size+1; i++)
    {
        if(!done[i] && dist[i] < smallest)
        {
            smallest = dist[i];
            vertex = i;
        }
    }
    return vertex;
}
// print graph
void Digraph::printGraph() const
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "vertex  adjacency list                  " << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int v = 1; v <= size; v++)
    {
        cout << setw(4) << v << " : ";
        array[v].print();
    }

    cout << "------------------------------------------------------------------" << endl;
}

// print shortest path tree for s
void Digraph::printTree() const
{
    cout << "----------------------" << endl;
    cout << "vertex    dist    path" << endl;
    cout << "----------------------" << endl;

    for (int v = 1; v <= size; v++)
    {
        cout << setw(4) << v << " :" << setw(8) << dist[v] << setw(8) << path[v] << endl;
    }

    cout << "----------------------" << endl;
}

// print shortest path from s to t
void Digraph::printPath(int t) const
{
    if (t < 1 || t > size)
    {
         cout << "\nERROR: expected target t in range 1.." << size << " !" << endl;
         return;
    }
    // *** TODO ***
    int temp = t;
    int find_path[size];
    int i = 0;

    while(path[temp] != 0)
    {
        find_path[i] = temp;
        temp = path[temp];
        i++;
    }
    find_path[i] = temp;

    for(int j = i; j > -1; j--)
    {
        cout << " " << find_path[j];
    }
    cout << " (" << dist[t] << ")" << endl;
}
