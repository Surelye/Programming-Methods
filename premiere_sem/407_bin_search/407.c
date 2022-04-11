#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int c, t, i;
    double left_bound = 0,
           right_bound = 1e9;
    
    scanf("%d %d", &c, &t);

    for (i = 0; i < 100; ++i)
    {
      double center = (left_bound) + (right_bound - left_bound) / 2;

      if (c * center * log(center) / log(2) <= t)
          left_bound = center;
      else
          right_bound = center;
    }

    printf("%.9f", left_bound);

    return (EXIT_SUCCESS);
}