#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  int u, v, weight;
  bool operator<(Edge const& other) { return ((weight < other.weight) || ((weight == other.weight) && (u < other.u)) || ((weight == other.weight) && (u == other.u) && (v < other.v))); }
};

unsigned int numberOfVertices, numberOfEdges;
vector<Edge> edges;
vector<pair<int, int>> res;
vector<int> treeId;

void getEdges ()
{
  int u, v, weight, i;

  for (i = 0; i < numberOfEdges; ++i)
    {
      cin >> u >> v >> weight;
      edges.push_back ({--u, --v, weight});
    }
}

void displayEdges ()
{
  int i;

  for (i = 0; i < numberOfEdges; ++i)
    cout << edges[i].u << " " << edges[i].v << " " << edges[i].weight << "\n";
}

void KruskalsAlgo ()
{
  int i, j, cost = 0;

  cin >> numberOfVertices >> numberOfEdges;
  getEdges ();
  sort (edges.begin (), edges.end ());

  for (i = 0; i < numberOfVertices; ++i)
    treeId.push_back (i);

  for (j = 0; j < numberOfEdges; ++j)
    {
      int u = edges[j].u, v = edges[j].v,  weight = edges[j].weight;
      if (treeId[u] != treeId[v])
        {
          cost += weight;
          res.push_back (make_pair (u, v));
          int oldId = treeId[v], newId = treeId[u];

          for (i = 0; i < numberOfVertices; ++i)
            if (treeId[i] == oldId)
              treeId[i] = newId;
        }
    }
  cout << cost << "\n";
  for (auto e : res)
    cout << ++e.first << " " << ++e.second << "\n";
}

int main ()
{
  KruskalsAlgo ();

  return (EXIT_SUCCESS);
}
/*
10 15
4 8 90
9 4 100
2 4 39
8 3 19
7 8 38
7 1 52
5 3 15
6 1 20
10 4 64
6 8 31
9 5 32
4 6 1
5 2 10
9 3 71
5 2 58
*/
