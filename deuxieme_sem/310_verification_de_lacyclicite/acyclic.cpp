#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<unsigned int>> adjLists;
vector<char> color;
vector<int> parent;
unsigned int numberOfVertices, numberOfEdges;
int cycleStart, cycleEnd;

void getAdjLists ()
{
  unsigned int i, verFrom, verTo;

  for (i = 0; i < numberOfEdges; ++i)
    {
      cin >> verFrom >> verTo;
      adjLists[--verFrom].push_back (--verTo);
    }
}

void displayAdjLists ()
{
  unsigned int i, j;

  for (i = 0; i < adjLists.size (); ++i)
    {
      cout << i << ": ";
      for (j = 0; j < adjLists[i].size (); ++j)
        cout << adjLists[i][j] << " ";
      cout << "\n";
    }
}

bool dfs (int v)
{
  color[v] = 1;

  for (int u : adjLists[v])
    {
      if (color[u] == 0)
        {
          parent[u] = v;
          if (dfs (u))
            return true;
        }
      else if (color[u] == 1)
        {
          cycleEnd = v;
          cycleStart = u;
          return true;
        }
    }

  color[v] = 2;
  return false;
}

void findCycle ()
{
  color.assign(numberOfVertices, 0);
  parent.assign(numberOfVertices, -1);
  cycleStart = -1;

  for (int v = 0; v < numberOfVertices; ++v)
    if (color[v] == 0 && dfs (v))
      break;

  if (cycleStart == -1)
    cout << "YES" << "\n";
  else
    {
      vector<unsigned int> cycle;
      cycle.push_back (cycleStart);

      for (int v = cycleEnd; v != cycleStart; v = parent[v])
        cycle.push_back(v);

      cycle.push_back(cycleStart);
      reverse (cycle.begin (), cycle.end ());

      cout << "NO\n" << cycle.size () - 1 << "\n";
      for (int v : cycle)
        cout << v + 1 << " ";
      cout << "\n";
    }
}

void acyclicityCheck ()
{
  int i;
  unsigned short numberOfTests;
  // cout << "INPUT THE NUMBER OF TESTS: ";
  cin >> numberOfTests;

  for (i = 0; i < numberOfTests; ++i)
    {
      // cout << "INPUT THE NUMBER OF VERTICES AND THE NUMBER OF EDGES: ";
      cin >> numberOfVertices >> numberOfEdges;
      adjLists.assign (numberOfVertices, vector<unsigned int> ());

      // cout << "NOW INPUT YOUR EDGES:\n";
      getAdjLists ();
      findCycle ();
    }
}

int main ()
{
  acyclicityCheck ();

  return (EXIT_SUCCESS);
}
