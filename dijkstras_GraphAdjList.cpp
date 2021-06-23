/* A simple representation of graph using STL (undirected graph)
following is the agjacency list representation: (numbers in the brackets represent weights)
0-(10)->1-(20)->4/
1-(10)->0-(30)->2-40->3-50->4/
2-30->1-60->3/
3-40->1-60->2-70->4/
4-20->0-50->1-70->3/
*/
//#include<bits/stdc++.h>
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
  int mindist(int u) {
    int min= INT_MAX,min_ind,x,w;
    for(auto itr=adj[u].begin();itr!=adj[u].end();itr++) {
      x = itr->first;
      w = itr->second;
      if (w<min) {min=w; min_ind=x;}
    }
  return min_ind;
    }
void dijkstras(int s) {
  bool spt[V];
  int u;
  int *dist= new int[V];
  for(int i=0;i<V;i++) {
    dist[i]=INT_MAX;
    spt[i]=false;
  }
  dist[s]=0;
  spt[s]=true;
  int count=1;
  while(count!=0) {
  u=mindist(s);
  spt[u]=true;
  for(auto itr=adj[u].begin();itr!=adj[u].end();itr++) {
    if (spt[itr->first]!=true && dist[u] != INT_MAX && dist[itr->first]>(dist[u]+(itr->second))) {
      dist[itr->first]=dist[u]+(itr->second);}
  }
  count=0;
  for(int j=0;j<V;j++) {
    if(!spt[j]) {count++;}
  }
  s=u;
  }
  int src=0;
  for(int i = 0; i<V; i++) {
   if(i != src)
      cout<<src<<" to "<<i<<", SP: "<<dist[i]<<endl;
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
   g.printGraph();
   g.dijkstras(s);

   return 0;
}
