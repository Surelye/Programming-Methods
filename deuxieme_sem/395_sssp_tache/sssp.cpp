#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
	int u, v;
  long long weight;
};

const long long INF = 5 * 1e18;

int numberOfVertices, numberOfEdges, startingVertex;
vector<bool> visited;
vector<long long> dist;
vector <vector <int>> adjLists;
vector<edge> edges;

void FordBellmanAlgo ()
{
  int i, j;
	dist[startingVertex] = 0;

	for (i = 0; i < numberOfVertices - 1; i++)
    {
      bool updated = false;
      for (j = 0; j < numberOfEdges; ++j)
        if (dist[edges[j].u] < INF)
          {
            dist[edges[j].v] = min (dist[edges[j].v], dist[edges[j].u] + edges[j].weight);
            if (dist[edges[j].v] < -INF) dist[edges[j].v] = -INF;
            updated = true;
          }
      if (!updated)
        break;
    }
}

void printPaths ()
{
  int i;

  for (i = 0; i < numberOfVertices; ++i)
		if (visited[i]) cout << "-" << "\n";
		else if (dist[i] == INF) cout << "*" << "\n";
    else cout << dist[i] << "\n";
}

void getData ()
{
  int _u, _v, i;
  long long _weight;

  cin >> numberOfVertices >> numberOfEdges >> startingVertex;
	--startingVertex;
  visited.assign (numberOfVertices, false);
	dist.assign (numberOfVertices, INF);
  adjLists.assign (numberOfVertices, vector<int> ());

	for (i = 0; i < numberOfEdges; i++)
    {
      cin >> _u >> _v >> _weight;
      --_u, --_v;
      edges.push_back ({_u, _v, _weight});
      adjLists[edges[i].u].push_back (edges[i].v);
    }
}

void bfs (int vertex)
{
  int i;

  queue<int> vertexQ;
  vertexQ.push (vertex);
  while (!vertexQ.empty ())
    {
      int v = vertexQ.front ();
      vertexQ.pop ();
      for (i = 0; i < adjLists[v].size (); ++i)
        {
          int to = adjLists[v][i];
          if (!visited[to])
            {
              visited[to] = true;
              vertexQ.push (to);
            }
        }
    }
}

void single_source_shortes_paths ()
{
  int i;

  getData ();
  FordBellmanAlgo ();

  vector<int> updates;
	for (i = 0; i < numberOfEdges; ++i)
		if (dist[edges[i].u] < INF)
			if (dist[edges[i].v] > dist[edges[i].u] + edges[i].weight)
        {
          dist[edges[i].v] = dist[edges[i].u] + edges[i].weight;
          updates.push_back (edges[i].v);
        }

	for (i = 0; i < updates.size (); ++i)
    bfs (updates[i]);
  printPaths ();
}

int main ()
{
  single_source_shortes_paths ();

	return (EXIT_SUCCESS);
}

/*
6 7 1
1 2 10
2 3 5
1 3 100
3 5 7
5 4 10
4 3 -18
6 1 -1
*/
