#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  unsigned short u, v;
  unsigned int weight;
  bool operator<(Edge const& other) { return
      ((weight < other.weight) || ((weight == other.weight) && (u < other.u)) || ((weight == other.weight) && (u == other.u) && (v < other.v))); }
};

unsigned short numberOfVertices;
unsigned int numberOfEdges;
vector<Edge> edges;
vector<unsigned short> parent, stat;

void getEdges ()
{
  unsigned short u, v;
  unsigned int i, weight;

  for (i = 0; i < numberOfEdges; ++i)
    {
      cin >> u >> v >> weight;
      edges.push_back ({--u, --v, weight});
    }
}

void makeSet (unsigned short v)
{
  parent[v] = v;
  stat[v] = 0;
}

unsigned short findSet (unsigned short v)
{
  if (v == parent[v])
    return v;
  return (parent[v] = findSet (parent[v]));
}

void unionSets (unsigned short a, unsigned short b)
{
  a = findSet (a);
  b = findSet (b);
  if (a != b)
    {
      if (stat[a] < stat[b])
	swap (a, b);
      parent[b] = a;
      if (stat[a] == stat[b])
	++stat[a];
    }
}

void kruskalsAlgo ()
{
  unsigned short i;
  double cost = 0;
  
  cin >> numberOfVertices >> numberOfEdges;
  getEdges ();

  vector<Edge> result;
  parent.resize (numberOfVertices);
  stat.resize (numberOfVertices);
  for (i = 0; i < numberOfVertices; ++i)
    makeSet (i);
  
  sort (edges.begin (), edges.end ());

  /*cout << "\n";
  for (Edge e : edges)
    cout << e.u << " " << e.v << " " << e.weight << "\n";
  cout << "\n";*/
  
  for (Edge e : edges)
    { 
      if (findSet (e.u) != findSet (e.v))
	{
	  cost += e.weight;
	  result.push_back (e);
	  unionSets (e.u, e.v);
	}
    }
  
  cout << cost << "\n";
  for (Edge e : result)
    cout << ++e.u << " " << ++e.v << "\n";
}

int main ()
{
  kruskalsAlgo ();

  return (EXIT_SUCCESS);
}
