/* A simple representation of graph using STL (undirected graph)
following is the agjacency list representation:
0->1->4/
1->0->4->2->3/
2->1->3/
3->1->4->2/
4->3->0->1/
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
class graph {
  int V;
  list<pair<int,int> > *adj;
public:
  graph(int V)
  {
    this->V = V;
    adj = new list<pair<int,int> > [V];
  }
  void addEdge(int u,int v,int wt) {
    adj[v].push_back(make_pair(u,wt));
    adj[u].push_back(make_pair(v,wt));
  }
  // A utility function to print the adjacency list
  void printGraph() {
    int v,w;
    for(int i=0;i<V;i++) {
      cout<<i;
    for(auto itr=adj[i].begin();itr!=adj[i].end();itr++) {
      v = itr->first;
      w = itr->second;
      cout<<"-"<< w <<"->"<<v;
    }
    cout<<endl;
  }
  }

};
// representation of graph

// Driver code
int main()
{
    int V = 5;
    //vector<int> adj[V];
    graph g(V);
   g.addEdge( 0, 1, 10);
   g.addEdge( 0, 4, 20);
   g.addEdge( 1, 2, 30);
   g.addEdge( 1, 3, 40);
   g.addEdge( 1, 4, 50);
   g.addEdge( 2, 3, 60);
   g.addEdge( 3, 4, 70);
    g.printGraph();
    return 0;
}
