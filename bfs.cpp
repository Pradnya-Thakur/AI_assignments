#include<iostream>
#include <list>
 
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
 // Pointer to an array containing adjacency lists
    list<int> *adj;  
public:
    Graph(int V);  
    void addEdge(int v, int w);
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;   //a queue for BFS
 
    visited[s] = true;   // Mark the current node as visited
    queue.push_back(s);  //enque current node
 
    list<int>::iterator i;
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    cout << "Breadth First Traversal is  ";
    g.BFS(0);
 
    return 0;
}
 