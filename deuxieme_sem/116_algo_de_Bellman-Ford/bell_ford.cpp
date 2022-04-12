#include <iostream>
#include <vector>

using namespace std;

struct edge { short vFrom, vTo, weight; };

const int INF = 1e9;

unsigned short numberOfVertices, numberOfEdges;
short edgeWeight;
vector<edge> edges;

void displayEdges ()
{
    for (int i = 0; i < numberOfEdges; ++i)
        cout << "<" << edges[i].vFrom << "->" << edges[i].vTo << " : " << edges[i].weight << ">" << (i == numberOfEdges - 1 ? "." : ", ");
    
    cout << '\n';
}

void getEdges ()
{
    int i;
    short vFrom, vTo, weight;

    for (i = 0; i < numberOfEdges; ++i)
    {
        cin >> vFrom >> vTo >> weight;
        edges[i] = { vFrom, vTo, weight };
    }
}

void FordBellmanAlgorithmMachinerie ()
{
    int i, j;
    vector<int> dist (numberOfVertices + 1, INF);

	dist[1] = 0;

	for (i = 0; i < numberOfVertices - 1; ++i)
		for (j = 0; j < numberOfEdges; ++j)
			if (dist[edges[j].vFrom] < INF)
				dist[edges[j].vTo] = min (dist[edges[j].vTo], dist[edges[j].vFrom] + edges[j].weight);
	
    for (i = 2; i <= numberOfVertices; ++i)
        if (dist[i] == INF) cout << "NO\n";
        else cout << dist[i] << '\n';
}

void FordBellmanAlgorithm ()
{
    cin >> numberOfVertices >> numberOfEdges;
    edges.assign (numberOfEdges, edge ());

    getEdges ();
    FordBellmanAlgorithmMachinerie ();
}

int main ()
{
    FordBellmanAlgorithm ();

    return (EXIT_SUCCESS);
}