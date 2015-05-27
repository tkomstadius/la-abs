/*********************************************
* file:	~\tnd004\lab\lab4b\graph.h           *
* remark:implementation of undirected graphs *
* file for students                          *
**********************************************/


#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "graph.h"
#include "edge.h"
#include "heap.h"
#include "dsets.h"

const int INFINITY = 9999;

// -- CONSTRUCTORS

Graph::Graph(int n)
{
    assert(n >= 1);
    array = new List[n + 1];
    size  = n;
}

// -- DESTRUCTOR

Graph::~Graph()
{
    delete[] array;
}

// -- MEMBER FUNCTIONS

// insert undirected edge (u, v) with weight w
// update weight w if edge (u, v) is present
void Graph::insertEdge(int u, int v, int w)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].insert(v, w);
    array[v].insert(u, w);
}

// remove undirected edge (u, v)
void Graph::removeEdge(int u, int v)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].remove(v);
    array[v].remove(u);
}

// Prim's minimum spanning tree algorithm
void Graph::mstPrim() const
{
    // *** TODO ***
    Edge edges[size+1];
    bool done[size+1];
    for(int i = 1; i < size+1; i++)
    {
        done[i] = false;
        Edge initial(0, 0, INFINITY);
        edges[i] = initial;
    }
    //choose a vertex
    int s = 1;
    int v = s;
    done[v] = true;
    Edge first(0, 0, 0);
    edges[v] = first;
    while(true)
    {
        Node* temp = array[v].getFirst();
        while(temp)
        {
            if(!done[temp->vertex] && temp->weight < edges[temp->vertex].weight)
            {
                Edge e(v, temp->vertex, temp->weight);
                edges[temp->vertex] = e;
                temp = array[v].getNext();
            }
            else
            {
                temp = array[v].getNext();
            }
        }
        //find smallest undone distance vertex
        v = INFINITY;
        int smallest = INFINITY;

        for(int j = 1; j < size+1; j++)
        {
            if(!done[j] && edges[j].weight < smallest)
            {
                smallest = edges[j].weight;
                v = j;
            }
        }

        if(v == INFINITY)
        {
            break;
        }
        done[v] = true;
    }

    int sum = 0;
    for(int j = 2; j < size+1; j++)
    {
        cout << edges[j] << endl;
        sum += edges[j].weight;
    }
    cout << "Total weight = " << sum << endl;
}

// Kruskal's minimum spanning tree algorithm
void Graph::mstKruskal() const
{
    // *** TODO ***
    Heap <Edge>H;
    DSets D(size);

    // H.heapify(edges);
    for (int i = 1; i <= size; ++i) {
        Node *p = array[i].getFirst();
        while (p)
        {
            if (i < p->vertex)
            {
                H.insert(Edge(i, p->vertex, p->weight));
            }
            p = p->next;
        }
    }

    int counter = 0, total = 0;
    while (counter < size - 1)
    {
        Edge w = H.deleteMin();
        if (D.find(w.head) != D.find(w.tail))
        {
            cout << w << endl;
            D.join(D.find(w.head), D.find(w.tail));
            total += w.weight;
            ++counter;
        }
    }

    cout << endl << "Total weight = " << total << endl;
}

// print graph
void Graph::printGraph() const
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "vertex  adjacency list                                            " << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int v = 1; v <= size; v++)
    {
        cout << setw(4) << v << " : ";
        array[v].print();
    }

    cout << "------------------------------------------------------------------" << endl;
}
