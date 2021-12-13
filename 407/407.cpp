#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int c, t, i;
    cin >> c >> t;
    double left_bound = 0,
           right_bound = 1e9;
    double epsilon = 1e-10;

    for (i = 0; i < 100; ++i)
    {        
        double center = left_bound + (right_bound - left_bound) / 2;

        if (c * center * log2(center) <= t)
            left_bound = center;
        else 
            right_bound = center;
    }

    return 0;
}