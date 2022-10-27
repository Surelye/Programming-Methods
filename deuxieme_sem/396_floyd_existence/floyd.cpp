#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 1e9;

unsigned short numberOfVertices;
vector<vector<int>> weightMatrix;

void displayMatrix (vector<vector<int>> mat)
{
  unsigned int i, j;

  for (i = 0; i < numberOfVertices; ++i)
    {
      for (j = 0; j < numberOfVertices; ++j)
        cout << mat[i][j] << " ";
      cout << "\n";
    }
}

void getData ()
{
  unsigned short i, j;
  string str_value;
  int converted;
  ifstream fin ("input.txt");

  fin >> str_value;
  numberOfVertices = (short)(stoi (str_value));
  weightMatrix.assign (numberOfVertices, vector<int> (numberOfVertices));

  for (i = 0; i < numberOfVertices; ++i)
      for (j = 0; j < numberOfVertices; ++j)
        {
          fin >> str_value;
          converted = (stoi (str_value));
          weightMatrix[i][j] = (converted == 0 ? INF : converted);
          if (i == j)
          weightMatrix[i][j] = min (0, weightMatrix[i][j]);
        }
  fin.close ();
}

// Алгоритм Флойда – Уоршела. Поскольку ребра графа имеют отрицательные веса, то аккуратно их обрабатываем:
// если на каком-то этапе обработки m[i][j] станет меньше -INF, то положим m[i][j] = -INF.
void floydAlgo () 
{
  unsigned short i, j, k;

  for (k = 0; k < numberOfVertices; ++k)
    for (i = 0; i < numberOfVertices; ++i)
      for (j = 0; j < numberOfVertices; ++j)
        if ((weightMatrix[i][k] < INF) && (weightMatrix[k][j] < INF))
          {
            weightMatrix[i][j] = min (weightMatrix[i][j], weightMatrix[i][k] + weightMatrix[k][j]);
            if (weightMatrix[i][j] < -INF) weightMatrix[i][j] = -INF;
          }
}

void writeMatrix (vector<vector<short>> mat)
{
  unsigned short i, j;
  ofstream fout ("output.txt");

  for (i = 0; i < numberOfVertices; ++i)
    {
      for (j = 0; j < numberOfVertices; ++j)
        fout << mat[i][j] << " ";
      fout << "\n";
    }
  fout.close ();
}

// Пути не существует, если для вершин путь в матрице = +INF. Кратчайшего не существует, если есть цикл отрицательного веса.
// Иначе кратчайший путь есть.

void floydExistence ()
{
  unsigned short i, j, k;

  getData ();
  vector<vector<short>> resMatrix (numberOfVertices, vector<short> (numberOfVertices));
  floydAlgo ();

  for (i = 0; i < numberOfVertices; ++i)
    for (j = 0; j < numberOfVertices; ++j)
      {
        if (weightMatrix[i][j] == INF) resMatrix[i][j] = 0;
        // Строим результирующую матрицу res. Если пути между вершинами i и j не существует, то устанавливаем res[i][j] = 0.
        //Иначе устанавливаем res[i][j] = 1, после чего ищем циклические пути.
        else
          {
            resMatrix[i][j] = 1;
            // Между вершинами i и j не существует кратчайшего пути, если для некоторой вершины k существует путь из i в k и из k в j,
            // а также существует цикл отрицательной длины, начинающийся и заканчивающийся в вершине k (в ней m[k][k] < 0).
            for (k = 0; k < numberOfVertices; ++k)
              if ((weightMatrix[k][k] < 0) && (weightMatrix[i][k] < INF) && (weightMatrix[k][j] < INF))
                resMatrix[i][k] = resMatrix[i][j] = resMatrix[k][j] = 2;
          }
      }
  writeMatrix (resMatrix);
}

int main ()
{
  floydExistence ();

  return (EXIT_SUCCESS);
}

Во всех остальных случаях считаем, что кратчайший путь между i и j существует.

 

Пример

Граф, приведенный в примере, имеет вид:



 

Реализация алгоритма

Матрицу смежности графа храним в массиве m. В массиве res будем строить результирующую матрицу. Значение плюс бесконечность положим равным INF.

 

#define INF 0x3F3F3F3F

#define MAX 101

int m[MAX][MAX], res[MAX][MAX];

 

Алгоритм Флойда – Уоршела. Поскольку ребра графа имеют отрицательные веса, то аккуратно их обрабатываем: если на каком-то этапе обработки m[i][j] станет меньше -INF, то положим m[i][j] = -INF.

 

void floyd(void)

{

  for(int k = 0; k < n; k++)

  for(int i = 0; i < n; i++)

  for(int j = 0; j < n; j++)

    if ((m[i][k] < INF) && (m[k][j] < INF))

    {

      if (m[i][k] + m[k][j] < m[i][j]) m[i][j] = m[i][k] + m[k][j];

      if (m[i][j] < -INF) m[i][j] = -INF;

    }

}

 

Основная часть программы. Читаем входную матрицу. На диагонали устанавливаем нули. Если между вершинами i и j нет ребра, то устанавливаем m[i][j] = INF.

 

scanf("%d",&n);

for(i = 0; i < n; i++)

for(j = 0; j < n; j++) 

{

  scanf("%d",&m[i][j]);

  if ((m[i][j] == 0) && (i != j)) m[i][j] = INF;

}

 

Запускаем алгоритм Флойда – Уоршела.

 

floyd();

 

Строим результирующую матрицу res. Если пути между вершинами i и j не существует, то устанавливаем res[i][j] = 0. Иначе устанавливаем res[i][j] = 1, после чего ищем циклические пути.

 

for(i = 0; i < n; i++)

for(j = 0; j < n; j++)

{

  if (m[i][j] == INF) res[i][j] = 0; else

  {

    res[i][j] = 1;

 

Между вершинами i и j не существует кратчайшего пути, если для некоторой вершины k существует путь из i в k и из k в j, а также существует цикл отрицательной длины, начинающийся и заканчивающийся в вершине k (в ней m[k][k] < 0).

 

    for(k = 0; k < n; k++)

      if ((m[k][k] < 0) && (m[i][k] < INF) && (m[k][j] < INF))

        res[i][k] = res[i][j] = res[k][j] = 2;

  }

}

 

Выводим результирующую матрицу res.

 

for(i = 0; i < n; i++)

{

  for(j = 0; j < n; j++)

    printf("%d ",res[i][j]);

  printf("\n");

}

/*
5
0 1 2 0 0
1 0 3 0 0
2 3 0 0 0
0 0 0 4 -1
0 0 0 -1 0
->
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 2 2
0 0 0 2 2
*/
