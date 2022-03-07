#include <iostream>
#include <vector>

using namespace std;

int numberOfVertices;
vector<int> permutation;

vector<vector<int>> getAdjacencyMatrix (vector<vector<int>> adjacencyMatrix)
{
  int i, j, placeholderElement;
    
  for (i = 0; i < numberOfVertices; ++i)
    {
      vector<int> placeholderRow;
      
      for (j = 0; j < numberOfVertices; ++j)
	{
	  cin >> placeholderElement;
	  placeholderRow.push_back(placeholderElement);
	}

      adjacencyMatrix.push_back(placeholderRow);
    }

  return (adjacencyMatrix);
}

void displayAdjacencyMatrix (vector<vector<int>> adjacencyMatrix)
{
  int i, j;

  for (i = 0; i < numberOfVertices; ++i)
    {
      for (j = 0; j < numberOfVertices; ++j)
	cout << adjacencyMatrix[i][j] << " ";
      
      cout << "\n";
    }      
}

bool inPermutation (int vertexNumber)
{
  int i;
  bool found = false;

  for (i = 0; i < permutation.size(); ++i)
    if (permutation[i] == vertexNumber)
      found = true;

  return (found);
}

int pickVertex (vector<vector<int>> adjacencyMatrix)
{
  int i, j;
  bool found;
  
  for (i = 0; i < numberOfVertices; ++i)
    {
      found = true;
      
      for (j = 0; j < numberOfVertices; ++j)	
	if (adjacencyMatrix[j][i] != 0)
	  {
	    found = false;
	    break;
	  }
      
      if (found && !inPermutation (i + 1))
	return (i + 1);
    }
  
  return -1;
}

vector<vector<int>> edgeRemovalProcedure (int vertexNumber, vector<vector<int>> adjacencyMatrix)
{
  int i;
  
  for (i = 0; i < numberOfVertices; ++i)
    adjacencyMatrix[vertexNumber][i] = 0;

  // cout << "\n";
  // displayAdjacencyMatrix (adjacencyMatrix);
  // cout << "\n";
  
  return (adjacencyMatrix);
}

void topologicalSorting (vector<vector<int>> adjacencyMatrix)
{
  int nextVertex;
  
  while (permutation.size() < numberOfVertices)
    {
      nextVertex = pickVertex (adjacencyMatrix);
      permutation.push_back (nextVertex);
      adjacencyMatrix = edgeRemovalProcedure (nextVertex - 1, adjacencyMatrix);
    }
}

int main ()
{
  vector<vector<int>> adjacencyMatrix;

  cin >> numberOfVertices;
  
  adjacencyMatrix = getAdjacencyMatrix (adjacencyMatrix);
  
  topologicalSorting (adjacencyMatrix);

  for (auto vertex : permutation)
    cout << vertex << " ";
  cout << "\n";
  
  return (EXIT_SUCCESS);
}
