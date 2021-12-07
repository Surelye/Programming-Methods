#include <stdio.h>

float find_x(int credit_sum, int number_of_months, int percent)
{
  float accumulator_numerator = 1;  
  float accumulator_denominator = 0;
  int i;

  for (i = 0; i < number_of_months; ++i)
    {      
      accumulator_denominator += accumulator_numerator;
      accumulator_numerator *= (1 + 1.0 * percent / 100);      
    }

  return (credit_sum * accumulator_numerator / accumulator_denominator);
}

int main(int argc, char * argv[])
{
  int credit_sum, number_of_months, percent;

  scanf("%d", &credit_sum);
  scanf("%d", &number_of_months);
  scanf("%d", &percent);

  printf("%.5f\n", find_x(credit_sum, number_of_months, percent));
}
