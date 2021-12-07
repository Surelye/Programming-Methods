#include <stdio.h>
#include <stdlib.h>
 
void swap(long long * first, long long * second)
{
  long long placeholder = *first;
  *first = *second;
  *second = placeholder;
}

long long k_order_statistics(long long elts[], int k, int array_size)
{ 
  int left = 0;
  int right = array_size - 1;

  while (left <= right)
    {
      if (right <= left + 1)
	{
	  if (right == left + 1 && elts[right] < elts[left])
	    swap(&elts[left], &elts[right]);
	  
	  return elts[k];	  
	}

      if (elts[left] > elts[right])
	swap(&elts[left], &elts[right]);

      if (elts[left + 1] > elts[right])
	swap(&elts[left + 1], &elts[right]);

      if (elts[left] > elts[left + 1])
	swap(&elts[left], &elts[left + 1]);

      long long pivot = elts[left + 1];
      int i = left + 1;
      int j = right;

      while (i <= j)
	{
	  while (elts[++i] < pivot);
	  while (elts[--j] > pivot);
	  if (i > j)
	    break;
	  swap(&elts[i], &elts[j]);
	}

      swap(&elts[j], &elts[left + 1]);
      if (j >= k)
	right = j - 1;
      if (i <= k)
	left = i;
    }
}

int main(int argc, char * argv[])
{
  int N, K, i;
  long A, B, C, R;
  scanf("%d %d", &N, &K);
  
  long long elts[N];
  scanf("%lld %lld %ld %ld %ld %ld",
  	&elts[0], &elts[1],
	&A, &B, &C, &R);
  
  for (i = 2; i < N; ++i)
    elts[i] = (A * elts[i - 2] + B * elts[i - 1] + C) % R;

  printf("%lld\n",  k_order_statistics(elts, K - 1, N));
  
  return (EXIT_SUCCESS);
}
