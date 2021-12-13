#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_lesser_k (vector<int> lengths, int length)
{
    int accumulator = 0;

    for (size_t i = 0; i < lengths.size(); ++i)
        if (lengths[i] < length)
            accumulator += lengths[i];
    
    return accumulator;
}

int main()
{
    int N, K, placeholder,
        min_length, accumulator = 0, 
        left_bound = 1, right_bound;
    vector <int> lengths;
    cin >> N >> K;

    for (size_t i = 0; i < N; i++)
    {
        cin >> placeholder;
        lengths.push_back(placeholder);
        accumulator += lengths[i];
    }
    right_bound = accumulator;

    if (accumulator < K)
    {
        cout << 0 << endl;
        return 0;
    }
    
    while (true) 
    {
        int center = (left_bound + right_bound) / 2;

        if (center * K <= accumulator - sum_lesser_k(lengths, center)) 
        {
            cout << center << endl;
            return 0;
        }
        else 
            right_bound = center;
    }


    return 0;
}