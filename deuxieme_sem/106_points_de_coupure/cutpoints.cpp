#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

unsigned short numberOfVertices, numberOfEdges;
vector<vector<short>> adjLists;
vector<bool> visited;
short timer = 0;
vector<short> tin, fup;
set<short> cutpoints;

void displayAdjLists ()
{
    int i, j;

    for (i = 1; i <= numberOfVertices; ++i)
    {
        cout << i << ": ";

        for (j = 0; j < adjLists[i].size (); ++j)
            cout << adjLists[i][j] << (j == adjLists[i].size () - 1 ? "." : ", ");

        cout << '\n';
    }
}

void getAdjLists ()
{
    int i, fVer, sVer;

    for (i = 0; i < numberOfEdges; ++i)
    {
        cin >> fVer >> sVer;

        adjLists[fVer].push_back (sVer);
        adjLists[sVer].push_back (fVer);
    }
}

void dfs (int v, int p = -1) 
{
	visited[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;

	for (int i = 0; i < adjLists[v].size(); ++i) 
    {
		int to = adjLists[v][i];

		if (to == p) 
            continue;

		if (visited[to])
			fup[v] = min (fup[v], tin[to]);
		else 
        {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);

			if (fup[to] >= tin[v] && p != -1)
				cutpoints.insert (v);

			++children;
		}
	}

	if (p == -1 && children > 1)
		cutpoints.insert (v);
}

void getCutpoints ()
{
    cin >> numberOfVertices >> numberOfEdges;

    adjLists.assign (numberOfVertices + 1, vector<short> ());
    getAdjLists ();

    visited.assign (numberOfVertices + 1, false);
    tin.assign (numberOfVertices + 1, 0), fup.assign (numberOfVertices + 1, 0);

    dfs (1);

    cout << cutpoints.size () << '\n';
    for (auto cutpoint : cutpoints)
        cout << cutpoint << ' ';

    cout << '\n';
}

int main ()
{
    getCutpoints ();

    return (EXIT_SUCCESS);
}