#include <stdio.h>
#include <stdlib.h>

int number_of_pieces(int lengths[], int array_size, int length)
{
  int i, number_of_pieces = 0;

  for (i = 0; i < array_size; ++i)
    number_of_pieces += lengths[i] / length;

  return number_of_pieces;
}

int main(int argc, char * argv[])
{
  int N, K, i,
    left_bound = 0,
    right_bound = 1e5,
    center;
  
  if (!scanf("%d %d", &N, &K))
    printf("AN ERROR OCCURRED.\n");

  int lengths[N];

  for (i = 0; i < N; ++i)
    if (!scanf("%d", &lengths[i]))
      printf("AN ERROR OCCURRED.\n");

  while (left_bound + 1 < right_bound)
    {
      center = left_bound + (right_bound - left_bound) / 2;

      if (K <= number_of_pieces(lengths, N, center))
	left_bound = center;
      else right_bound = center;  
    }

  printf("%d\n", left_bound);
  
  return (EXIT_SUCCESS);
}
