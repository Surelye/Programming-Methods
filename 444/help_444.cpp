#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double INF = 1e9 + 1;
const double EPS = 1e-9;

bool check(vector<pair<int, int>>& start, double t) {

    double right = -(1e19 + 100);
    for (int i = 0; i < size(start); ++i) {
        auto x = start[i].first + start[i].second * t;
        if (start[i].second > 0) {
            right = max(right, x);
        }
        else if (abs(x - right) < EPS || x < right) {
            return true;
        }
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    double left = 0, right = INF;

    if (!check(a, right)) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < 100; ++i) {
        double middle = (left + right) / 2;

        printf("LEFT IS %.6f, RIGHT IS %.6f\n", left, right);

        if (check(a, middle)) {
            right = middle;
        }
        else {
            left = middle;
        }
    }

    cout << setprecision(9) << fixed;
    cout << right << endl;

    return 0;
}