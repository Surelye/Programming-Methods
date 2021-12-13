#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_greater(float credit_sum, int number_of_months, int percent, double check_value)
{
    int i;

    for (i = 0; i < number_of_months; ++i)
        credit_sum += 1.0 * credit_sum * percent / 100 - check_value;
    
    return (credit_sum >= 0);
}

int main(int argc, char * argv[])
{
    int number_of_months, percent, i;
    float credit_sum,
           left_bound = 0,
           right_bound,
           center;

    if (!scanf("%f %d %d", &credit_sum, &number_of_months, &percent))
    {
        printf("AN ERROR OCCURRED.\n");
        exit(1);
    }

    right_bound = credit_sum * (1 + 1.0 * percent / 100);

    for (i = 0; i < 100; ++i)
    {
        center = left_bound + (right_bound - left_bound) / 2;

        if (is_greater(credit_sum, number_of_months, percent, center))
            left_bound = center;
        else right_bound = center;
    }
    
    printf("%.5f\n", left_bound);

    return (EXIT_SUCCESS);
}