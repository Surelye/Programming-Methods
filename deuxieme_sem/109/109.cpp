/*
#include <iostream>
#include <vector>

using namespace std;

short vertexFrom, vertexTo;
bool vertexToFound = false;
vector<bool> visited;
vector<short> path;

void inputMatrix (vector<vector<short>>& matrix, short dimension)
{
    short i, j, elt;

    for (i = 0; i < dimension; ++i)
    {
        vector<short> row;

        for (j = 0; j < dimension; ++j)
        {
            cin >> elt;
            row.push_back (elt);
        }

        matrix.push_back (row);
    }
}

vector<short> getAdjList (vector<short> row)
{
    int i;
    vector<short> adjList;

    for (i = 0; i < row.size (); ++i)
        if (row[i] == 1)
            adjList.push_back (i + 1);

    return (adjList);
}

void dfs (vector<vector<short>> matrix, short vertFrom)
{
    visited[vertFrom - 1] = true;
    path.push_back (vertFrom);

    if (vertFrom == vertexTo)
    {
        visited.assign (matrix.size (), true);
        vertexToFound = true;
        return;
    }

    for (short vertex : getAdjList (matrix[vertFrom - 1]))
        if (!visited[vertex - 1])
            dfs (matrix, vertex);
}

void extractPath ()
{
    int i;

    if (!vertexToFound)
    {
        cout << -1 << "\n";
        return;
    }
    else
    {
        cout << path.size () - 1 << "\n";

        for (i = 0; i < path.size (); ++i)
            cout << path[i] << " ";

        cout << "\n";
    }   
}

int main ()
{
    short dimension;
    vector<vector<short>> matrix;

    cin >> dimension >> vertexFrom >> vertexTo;

    visited.assign (dimension, false);

    inputMatrix (matrix, dimension);
    dfs (matrix, vertexFrom);
    extractPath ();

    return (EXIT_SUCCESS);
} */

/*
5 1 5
0 1 1 0 1
1 0 0 1 1
1 0 0 0 1
0 1 0 0 1
1 1 1 1 0
*/

#include <iostream>
#include <vector>
 
using namespace std;

short vertexFrom, vertexTo;
vector<short> sequence, path;
vector<bool> visited;

void inputMatrix (vector<vector<short>>& matrix, short dimension)
{
    short i, j, elt;

    for (i = 0; i < dimension; ++i)
    {
        vector<short> row;

        for (j = 0; j < dimension; ++j)
        {
            cin >> elt;
            row.push_back (elt);
        }

        matrix.push_back (row);
    }
}

void dfs (vector<vector<short>> matrix, short vertFrom) 
{
    visited[vertFrom] = true;

    for (short i = 0; i < matrix[vertFrom].size (); ++i)    
        if (matrix[vertFrom][i] && !visited[i]) 
        {
            sequence[i] = vertFrom;
            dfs (matrix, i);
        }
}
 
void extractPath ()
{
    short i;

    while (sequence[vertexTo] != -1) 
    {
        path.push_back (vertexTo);
        vertexTo = sequence[vertexTo];
    }
 
    if (vertexFrom == vertexTo) 
        path.push_back (vertexTo);
    else 
    {
        cout << -1;
        return;
    }
 
    cout << path.size () - 1 << "\n";

    for (i = path.size () - 1; i >= 0; --i)
        cout << path[i] + 1 << " ";
}

int main () 
{
    short dimension;
    vector<vector<short>> matrix;

    cin >> dimension >> vertexFrom >> vertexTo;
    --vertexTo;

    visited.assign (dimension, false);
    sequence.assign (dimension, -1);

    inputMatrix (matrix, dimension);
    dfs (matrix, --vertexFrom);
    extractPath ();    
 
    return (EXIT_SUCCESS);
}