#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<double, double> cost_function_derivative(pair<double, double> point, vector< pair <int, int> > points)
{
    double x_accumulator = 0;
    double y_accumulator = 0;
    double x_ = point.first;
    double y_ = point.second;

    for (size_t i = 0; i < points.size(); ++i)
    {
        x_accumulator += (x_ - points[i].first) / sqrt((x_ - points[i].first) * (x_ - points[i].first) + (y_ - points[i].second) * (y_ - points[i].second));
        y_accumulator += (y_ - points[i].second) / sqrt((x_ - points[i].first) * (x_ - points[i].first) + (y_ - points[i].second) * (y_ - points[i].second));
    }
    
    return make_pair(x_accumulator, y_accumulator);
}

double cost_function(pair<double, double> point, vector< pair <int, int> > points)
{
    double cost = 0;
    double x_ = point.first;
    double y_ = point.second;

    for (size_t i = 0; i < points.size(); ++i)
        cost += sqrt((x_ - points[i].first) * (x_ - points[i].first) + (y_ - points[i].second) * (y_ - points[i].second));
    
    return cost;
}

int main()
{
    int number_of_points, first_value, second_value,
        x_max = -10001, x_min = 10001, y_max = -10001, y_min = 10001;
    double alpha = 0.03;
    vector< pair <int, int> > points;

    cin >> number_of_points;
    for (size_t i = 0; i < number_of_points; ++i)
    {
        cin >> first_value >> second_value;
        points.push_back(make_pair(first_value, second_value));
    }
    
    if (number_of_points == 1)
    {
        cout << points[0].first << " " << points[0].second << endl;
        return 0;
    }

    for (size_t i = 0; i < points.size(); i++)
    {
        if (points[i].first > x_max)
            x_max = points[i].first;
        if (points[i].first < x_min)
            x_min = points[i].first;
        if (points[i].second > y_max)
            y_max = points[i].second;
        if (points[i].second < y_min)
            y_min = points[i].second;
    }

    pair<double, double> guess = make_pair((1.0 * (x_max + x_min)) / 2, (1.0 * (y_max + y_min)) / 2);

    for (size_t i = 0; i < 1000; ++i)
    {
        double temp_x, temp_y;
        // cout << "At step " << i << " cost function returned: " << cost_function(guess, points) << endl;
        
        temp_x = guess.first - alpha * cost_function_derivative(guess, points).first;
        temp_y = guess.second - alpha * cost_function_derivative(guess, points).second;
        guess.first = temp_x;
        guess.second = temp_y;
    }
    
    cout << endl << guess.first << " " << guess.second << endl;

    return 0;
}