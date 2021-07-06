/*Dijkstras algorithm for finding shortest path for graphs represented by adjacency list*/

#include<bits/stdc++.h>
#include<iostream>
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

 //function which returns the index of vertex with minimum distance value, from
 // the set of vertices not yet visited
    int mindist(int dist[], bool spt[])
    {
        // Initialize min value
        int min = INT_MAX, min_ind;

        for (int v = 0; v < V; v++)
            if (spt[v] == false && dist[v] <= min)
                min = dist[v], min_ind = v;

        return min_ind;
    }
    bool count(bool spt[]) {
        int c=0;
        for(int i=0;i<V;i++) {
            if(spt[i] == true) {c++;}
        }
        if(c==V) {return true;}
        else {return false;}
    }
void dijkstras(int s) {
  bool spt[V];
  int u;
  int dist[V];
  for(int i=0;i<V;i++) {
    dist[i]=INT_MAX;
    spt[i]=false;
  }
  dist[s]=0;
  while(count(spt)!=true) {
  u=mindist(dist,spt);
  spt[u]=true;
  for(auto itr=adj[u].begin();itr!=adj[u].end();itr++) {
    int v = (*itr).first;
    int wt = (*itr).second;
    if (!spt[v] && dist[v]>(dist[u]+wt)) {
      dist[v]=dist[u]+wt;}
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
    /* A simple representation of graph using STL (undirected graph)
following is the agjacency list representation: (numbers in the brackets represent weights)
0-(10)->1-(20)->4/
1-(10)->0-(30)->2-(40)->3-(50)->4/
2-(30)->1-(60)->3/
3-(40)->1-(60)->2-(70)->4/
4-(20)->0-(50)->1-(70)->3/
*/
    int V = 5,s=0;
    graph g(V);
   g.addEdge( 0, 1, 10);
   g.addEdge( 0, 4, 20);
   g.addEdge( 1, 2, 30);
   g.addEdge( 1, 3, 40);
   g.addEdge( 1, 4, 50);
   g.addEdge( 2, 3, 60);
   g.addEdge( 3, 4, 70);
   g.dijkstras(s);

   return 0;
}
