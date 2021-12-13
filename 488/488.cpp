#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair< double, vector<int> > best_fractions(vector< pair<int, int> > pairs, double check_value, int number_of_best_fit_pairs)
{
    int i;
    vector< pair< double, double > > fraction_values;
    pair< double, vector<int> > fraction_value_and_positions;

    for (i = 0; i < pairs.size(); ++i)
        fraction_values.push_back(make_pair(pairs[i].second * check_value - pairs[i].first, i + 1));
    
    sort(fraction_values.begin(), fraction_values.end());

    for (i = 0; i < number_of_best_fit_pairs; ++i)
    {
        fraction_value_and_positions.first += fraction_values[i].first;
        fraction_value_and_positions.second.push_back(fraction_values[i].second);
    }

    return fraction_value_and_positions;
}

int main(int argc, char * argv[])
{
    int number_of_pairs, number_of_best_fit_pairs, i;
    double left_bound = 0,
           right_bound = 1e10,
           epsilon = 1e-7,
           center;

    cin >> number_of_pairs >> number_of_best_fit_pairs;

    vector< pair<int, int> > pairs(number_of_pairs);
    pair< double, vector<int> > approx_fractions;
    vector<int> positions;

    for (i = 0; i < number_of_pairs; ++i)
        cin >> pairs[i].first >> pairs[i].second;
    
    while (right_bound - left_bound > epsilon)
    {
        center = left_bound + (right_bound - left_bound) / 2;

        approx_fractions = best_fractions(pairs, center, number_of_best_fit_pairs);
        if (approx_fractions.first < 0)
        {
            left_bound = center;
            positions = approx_fractions.second;
        }
        else right_bound = center;
    }

    printf("%.6f\n", left_bound);

    for (i = 0; i < number_of_best_fit_pairs; ++i)
        cout << positions[i] << " ";

    return 0;
}