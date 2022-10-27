#include <iostream>
#include <vector>

using namespace std;

int numberOfVertices;

void getWeightMatrix (vector<vector<int>>& weightMatrix)
{
	int i, j, weightPlaceholder;

  for (i = 0; i < numberOfVertices; ++i)
  	{
    	vector<int> rowPlaceholder;

	    for (j = 0; j < numberOfVertices; ++j)
        {
          cin >> weightPlaceholder;

          if (weightPlaceholder == 0)
	      		rowPlaceholder.push_back (10e6 + 1);
          else rowPlaceholder.push_back (weightPlaceholder);
        }

      weightMatrix.push_back (rowPlaceholder);
    }
}

void displayMatrix (vector<vector<int>> Matrix)
{
  int i, j;

  for (i = 0; i < numberOfVertices; ++i)
  	{
    	for (j = 0; j < numberOfVertices; ++j)
        if (Matrix[i][j] == 10e6 + 1)
          cout << 0 << " ";
        else cout << Matrix[i][j] << " ";

      cout << "\n";
    }
}

void floyd (vector<vector<int>>& pathMat)
{
	int i, j, k, dimension = pathMat.size();

	for (k = 0; k < dimension; ++k)
		for (i = 0; i < dimension; ++i)
			for (j = 0; j < dimension; ++j)
				pathMat[i][j] = min(pathMat[i][j], pathMat[i][k] + pathMat[k][j]);
}

int main ()
{
  vector<vector<int>> weightMatrix;

  cin >> numberOfVertices;

  getWeightMatrix (weightMatrix);
  floyd (weightMatrix);
  displayMatrix (weightMatrix);

  return (EXIT_SUCCESS);
}

/*
5
0 1 1 0 1
1 0 0 1 1
1 0 0 0 1
0 1 0 0 1
1 1 1 1 0
*/
