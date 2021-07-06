/*Dijkstraâs Algorithm for Adjacency List Representation*/

/* A simple representation of graph  (undirected graph)
following is the agjacency list representation: (numbers in the brackets represent weights)
0-(10)->1-(20)->4/
1-(10)->0-(30)->2-(40)->3-(50)->4/
2-(30)->1-(60)->3/
3-(40)->1-(60)->2-(70)->4/
4-(20)->0-(50)->1-(70)->3/
*/
#include<bits/stdc++.h>
#include<vector>
#include<list>
using namespace std;

class graph {
  int V;
  list<pair<int,int> > *adj;
public:
  graph(int V)
  {
    this->V = V;
    adj = new list<pair<int,int> > [V];
  }
  // A utility function to add an edge in an
  // undirected graph.
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
// function for impementing dijkstras algo & printing shortest path
void dijkstras(int s) {
  int u;
  int dist[V];
  for(int i=0;i<V;i++) {
    dist[i]=INT_MAX;
  }
  dist[s]=0;
  // initiallizing a priority queue
  priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
  pq.push(make_pair(0,s));
  while(!pq.empty()) {
  u= pq.top().second;
  pq.pop();
  for(auto itr=adj[u].begin();itr!=adj[u].end();itr++) {
    int v = (*itr).first;
    int wt = (*itr).second;
    if (dist[v]>(dist[u]+(wt))) {
      dist[v]=dist[u]+(wt);
      pq.push(make_pair(dist[v],v));
    }
  }
  }
    for(int i = 0; i<V; i++) {
       if(i != s)
          cout<<s<<" to "<<i<<", SP: "<<dist[i]<<endl;
    }
  }

};

// Driver code
int main()
{
    int V = 5,s=0;
    graph g(V);
   g.addEdge( 0, 1, 10);
   g.addEdge( 0, 4, 20);
   g.addEdge( 1, 2, 30);
   g.addEdge( 1, 3, 40);
   g.addEdge( 1, 4, 50);
   g.addEdge( 2, 3, 60);
   g.addEdge( 3, 4, 70);
   // uncomment below line for graph representation
   //g.printGraph();
   g.dijkstras(s);

   return 0;
}
