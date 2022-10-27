#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int vertexFrom, vertexTo;
vector<int> ancest;
vector<bool> visited;

void inputMatrix (vector<vector<int>>& matrix, int dimension)
{
  int i, j, elt;

  for (i = 0; i < dimension; ++i)
    {
    	vector<int> row;

      for (j = 0; j < dimension; ++j)
        {
          cin >> elt;

          if (elt == 1)
            row.push_back (j);
        }

      matrix.push_back (row);
    }
}

void extractPath ()
{
	if (!visited[vertexTo])
		cout << -1 << "\n";
	else
    {
      vector<int> path;

      for (int vert = vertexTo; vert != -1; vert = ancest[vert])
        path.push_back (vert);

      reverse (path.begin (), path.end ());

      cout << path.size () - 1 << "\n";
      for (int i = 0; i < path.size (); ++i)
        cout << path[i] + 1 << " ";
    }
}

void bfs (vector<vector<int>> matrix, int vertFrom, int dimension)
{
	int i;
  queue<int> vertexQ;

	vertexQ.push (vertFrom);
	visited[vertFrom] = true;
	ancest[vertFrom] = -1;

	while (!vertexQ.empty ())
    {
      int curVert = vertexQ.front ();
      vertexQ.pop ();

      for (i = 0; i < matrix[curVert].size (); ++i)
        {
          int to = matrix[curVert][i];

          if (!visited[to])
            {
              visited[to] = true;
              vertexQ.push (to);
              ancest[to] = curVert;
            }
        }
    }

	extractPath ();
}
int main ()
{
	int dimension;
	vector<vector<int>> matrix;

	cin >> dimension >> vertexFrom >> vertexTo;
	--vertexFrom, --vertexTo;

	visited.assign (dimension, false);
	ancest.assign (dimension, 0);

	inputMatrix (matrix, dimension);
	bfs (matrix, vertexFrom, dimension);
}

/*
5 1 5
0 1 1 0 1
1 0 0 1 1
1 0 0 0 1
0 1 0 0 1
1 1 1 1 0
*/
