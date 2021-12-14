#include <iostream>
#include <vector>

using namespace std;

bool collision(vector< pair<int, int> > particle_description, double epsilon, double time)
{
    int i;
    double max_momentum = -1e20;

    for (i = 0; i < particle_description.size(); ++i)
    {
        double particle_momentum = particle_description[i].first + particle_description[i].second * time;

        if (particle_description[i].second > 0) 
            max_momentum = particle_momentum > max_momentum ? particle_momentum : max_momentum;
        else if (abs(max_momentum - particle_momentum) < epsilon || particle_momentum < max_momentum)
            return true;
    }

    return false;    
}

int main(int argc, char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number_of_particles, i, j = 0;
    double left_bound = 0,
           right_bound = 1e9,
           epsilon = 1e-10,
           center;
    cin >> number_of_particles;

    vector<pair <int, int> > particle_description(number_of_particles);

    for (i = 0; i < number_of_particles; ++i)
        cin >> particle_description[i].first >> particle_description[i].second;

    while (particle_description[j].second < 0) ++j;
    while (j < number_of_particles && particle_description[j].second > 0) ++j;

    if (j == number_of_particles) 
    {
        printf("%d\n", -1);
        return 0;
    }

    for (i = 0; i < 100; ++i)
    {
        center = left_bound + (right_bound - left_bound) / 2;

        if (collision(particle_description, epsilon, center))
            right_bound = center;
        else 
            left_bound = center;            
    }
    
    printf("%.9f\n", left_bound);
}