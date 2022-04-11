#include <iostream>
#include <vector>
#include <utility>

using namespace std;

unsigned short numberOfVertices, numberOfEdges, vertexFrom, vertexTo;
const int INF = 1e9;

void display (vector<vector<pair<short, short>>> adjLists)
{
    int i, j;

    for (i = 0; i < adjLists.size (); ++i)
    {
        cout << i + 1 << ": ";

        for (j = 0; j < adjLists[i].size (); ++j)
            cout << '(' << adjLists[i][j].first + 1 << ", " << adjLists[i][j].second << ')' << (j == adjLists[i].size () - 1 ? "." : ", ");
    
        cout << '\n';
    }
}

void dijkstra ()
{
    short i, j, fVer, sVer, edgeValue;

    cin >> numberOfVertices >> numberOfEdges >> vertexFrom >> vertexTo;

    vector<vector<pair<short, short>>> adjLists (numberOfVertices);
    vector<int> dist (numberOfVertices, INF), path (numberOfVertices);
    vector<bool> visited (numberOfVertices, false);

    for (i = 0; i < numberOfEdges; ++i)
    {
        cin >> fVer >> sVer >> edgeValue;
        adjLists[fVer - 1].push_back (make_pair (sVer - 1, edgeValue));
        adjLists[sVer - 1].push_back (make_pair (fVer - 1, edgeValue));
    }

    dist[vertexFrom - 1] = 0;

    for (i = 0; i < numberOfVertices; ++i)
    {
        int v = -1;

        for (j = 0; j < numberOfVertices; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;
        visited[v] = true;

        for (j = 0; j < adjLists[v].size (); ++j)
        {
            int to = adjLists[v][j].first, 
                     len = adjLists[v][j].second;
            
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                path[to] = v;
            }
        }
    }

    if (dist[vertexTo - 1] == INF)
        cout << -1 << '\n';
    else cout << dist[vertexTo - 1] << '\n';
}

int main ()
{
    dijkstra ();

    return (EXIT_SUCCESS);
}