#include <iostream>
#include <vector>

using namespace std;

int numberOfVertices;

vector<vector<int>> getWeightMatrix (vector<vector<int>> weightMatrix)
{
  int i, j, weightPlaceholder;
    
  for (i = 0; i < numberOfVertices; ++i)
    {
      vector<int> rowPlaceholder;
      
      for (j = 0; j < numberOfVertices; ++j)
	{
	  cin >> weightPlaceholder;
	  rowPlaceholder.push_back (weightPlaceholder);
	}

      weightMatrix.push_back (rowPlaceholder);
    }

  return (weightMatrix);
}

void displayWeightMatrix (vector<vector<int>> weightMatrix)
{
  int i, j;

  for (i = 0; i < numberOfVertices; ++i)
    {
      for (j = 0; j < numberOfVertices; ++j)
	cout << weightMatrix[i][j] << " ";

      cout << "\n";
    }
}

int main ()
{
  vector<vector<int>> weightMatrix;

  cin >> numberOfVertices;
  
  weightMatrix = getWeightMatrix (weightMatrix);
  displayWeightMatrix (weightMatrix);
  
  return (EXIT_SUCCESS);
}
