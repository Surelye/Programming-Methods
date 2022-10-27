#include <iostream>
#include <vector>

using namespace std;

const unsigned int INF = 1e9;

unsigned short numberOfVertices;
unsigned int numberOfEdges;
vector<vector<unsigned short>> weightAdjMatrix;
vector<short> parent; // array to store constructed MST
vector<unsigned int> key; // key values used to pick minimum weight edge 
vector<bool> mstSet; // represents the set of vertices included in the mst

void getAdjMatrix ()
{
    unsigned int i;
    unsigned short verFrom, verTo, weight;

    for (i = 0; i < numberOfEdges; ++i)
    {
        cin >> verFrom >> verTo >> weight;
        --verFrom, --verTo;
        weightAdjMatrix[verFrom][verTo] = weight;
        weightAdjMatrix[verTo][verFrom] = weight;
    }
}

unsigned int minKey ()
{
    unsigned int min = INF + 1;
    unsigned short min_index;

    for (int v = 0; v < numberOfVertices; ++v)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return (min_index);
}

void PrimsAlgorithm ()
{
    int i, j;

    cin >> numberOfVertices >> numberOfEdges;

    weightAdjMatrix.assign (numberOfVertices, vector<unsigned short> (numberOfVertices, 0));
    parent.assign (numberOfVertices, 0), key.assign (numberOfVertices, INF);
    mstSet.assign (numberOfVertices, false);

    getAdjMatrix ();

    key[0] = 0;
    parent[0] = -1;

    for (i = 0; i < numberOfVertices - 1; ++i)
    {
        unsigned int vert = minKey ();
        mstSet[vert] = true;

        for (j = 0; j < numberOfVertices; ++j)
            if (weightAdjMatrix[vert][j] && !mstSet[j] && weightAdjMatrix[vert][j] < key[j])
                parent[j] = vert, key[j] = weightAdjMatrix[vert][j];
    }

    unsigned int mstWeight = 0;
    for (i = 1; i < numberOfVertices; ++i)
        mstWeight += weightAdjMatrix[i][parent[i]];
    cout << mstWeight << "\n";

    for (i = 1; i < numberOfVertices; ++i)
        cout << parent[i] + 1 << " " << i + 1 << "\n";
}

int main ()
{
    PrimsAlgorithm ();

    return (EXIT_SUCCESS);
}
