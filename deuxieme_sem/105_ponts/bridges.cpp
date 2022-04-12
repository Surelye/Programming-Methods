#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<short, int>>> adjLists;
unsigned short numberOfVertices;
int numberOfEdges;
vector<bool> visited;
vector<short> tin, fup;
vector<int> bridges;
short timer;


void displayAdjLists (vector<vector<pair<short, int>>> adjLists)
{
    int i, j;

    for (i = 1; i <= numberOfVertices; ++i)
    {
        cout << i << ": ";

        for (j = 0; j < adjLists[i].size (); ++j)
            cout << "<" << adjLists[i][j].first << ", " << adjLists[i][j].second << ">" << (j == adjLists[i].size () - 1 ? "." : ", ");

        cout << '\n';
    }
}

void getAdjLists ()
{
    int i;
    short fVer, sVer;

    for (i = 1; i <= numberOfEdges; ++i)
    {
        cin >> fVer >> sVer;

        adjLists[fVer].push_back (make_pair (sVer, i));
        adjLists[sVer].push_back (make_pair (fVer, i));
    }
}

int findIdx (short v, short to)
{
    int i;

    for (i = 0; i < adjLists[v].size (); ++i)
        if (adjLists[v][i].first == to)
            return (adjLists[v][i].second);

    return (-1);
}

void dfs (short v, short p = -1)
{
	visited[v] = true;
	tin[v] = fup[v] = timer++;

	for (int i = 0; i < adjLists[v].size (); ++i) 
    {
		short to = adjLists[v][i].first;

		if (to == p)
            continue;

		if (visited[to])
			fup[v] = min (fup[v], tin[to]);
		else 
        {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);

			if (fup[to] > tin[v])
			    bridges.push_back (findIdx (v, to));
		}
	}
}
 

void findBridgesMachinerie ()
{
    int i;
	timer = 0;

	for (i = 1; i <= numberOfVertices; ++i)
		if (!visited[i])
			dfs (i);
}

void findBridges ()
{
    cin >> numberOfVertices >> numberOfEdges;

    adjLists.assign (numberOfVertices + 1, vector<pair<short, int>> ());
    getAdjLists ();
    
    visited.assign (numberOfVertices + 1, false);
    tin.assign (numberOfVertices + 1, 0), fup.assign (numberOfVertices + 1, 0);

    findBridgesMachinerie ();

    int numberOfBridges = bridges.size ();

    cout << numberOfBridges << '\n';

    sort (bridges.begin (), bridges.end ());
    for (int i = 0; i < numberOfBridges; ++i)
        cout << bridges[i] << " ";

    cout << '\n';
}

int main ()
{
    findBridges ();    

    return (EXIT_SUCCESS);
}