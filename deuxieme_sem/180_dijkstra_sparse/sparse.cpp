#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const unsigned int INF = 1e9;

unsigned short numberOfVertices;
unsigned int numberOfEdges;
vector<vector<pair<unsigned int, unsigned short>>> adjLists;
vector<unsigned int> dist;
vector<short> pred;

void displayAdjLists ()
{
  unsigned short i;
  unsigned int j;

  for (i = 0; i < adjLists.size (); ++i)
    {
      cout << i + 1 << ": ";
      for (j = 0; j < adjLists[i].size (); ++j)
        cout << "<" << adjLists[i][j].second + 1 << ", " << adjLists[i][j].first << ">" << (j == adjLists[i].size () - 1 ? "." : ", ");
      cout << "\n";
    }
}

void getAdjLists ()
{
  unsigned short vFrom, vTo;
  unsigned int weight, i;

  for (i = 0; i < numberOfEdges; ++i)
    {
      cin >> vFrom >> vTo >> weight;
      --vFrom, --vTo;
      adjLists[vFrom].push_back ({weight, vTo});
      adjLists[vTo].push_back ({weight, vFrom});
    }
}

void DijkstraSparse ()
{
  cin >> numberOfVertices >> numberOfEdges;
  adjLists.assign (numberOfVertices, vector<pair<unsigned int, unsigned short>> ());
  getAdjLists ();

  dist.assign (numberOfVertices, INF);
  pred.assign (numberOfVertices, -1);

  dist[0] = 0;

  set<pair<int, int>> vertexQ;
  vertexQ.insert ({0, 0});

  while (!vertexQ.empty ())
    {
      int v = vertexQ.begin()->second;
      vertexQ.erase (vertexQ.begin());

      for (auto edge : adjLists[v])
        {
          unsigned short to = edge.second;
          unsigned int len = edge.first;

          if (dist[v] + len < dist[to])
            {
              vertexQ.erase ({dist[to], to});
              dist[to] = dist[v] + len;
              pred[to] = v;
              vertexQ.insert ({dist[to], to});
            }
        }
    }
}

void extractPath ()
{
  short v;
  vector<unsigned short> path;

  for (v = numberOfVertices - 1; v != -1; v = pred[v])
    path.push_back (v);

  reverse (path.begin(), path.end());

  for (int i = 0; i < path.size (); ++i)
    cout << path[i] + 1 << " ";
}


int main ()
{
  DijkstraSparse ();

  if (dist[numberOfVertices - 1] == INF)
    cout << "No solution\n";
  else extractPath ();

  return (EXIT_SUCCESS);
}
