#include <iostream>
#include <algorithm>

using namespace std;
 
int Find(long long a[], int n, int k) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
		
		// --- выход из сортировки
        if (right <= left + 1) {
			// последняя замена
            if (right == left + 1 && a[right] < a[left])
                swap (a[left], a[right]);
            return a[k];
        }

 
        if (a[left] > a[right])
            swap (a[left], a[right]);

        if (a[left + 1] > a[right])
            swap (a[left + 1], a[right]);

        if (a[left] > a[left + 1])
            swap (a[left], a[left + 1]);
            
        int pivot = a[left + 1];
        int i = left + 1;
        int j = right;
        while (i <= j) {
            while (a[++i] < pivot); 
            while (a[--j] > pivot);
            if (i > j) break;
            swap(a[i], a[j]);
        }
        swap(a[j], a[left + 1]);
        if (j >= k) right = j - 1;
        if (i <= k) left = i;
    }
}
 
int main() {
    int N, K;
    cin >> N >> K;

    long long a[N];
    cin >> a[0] >> a[1];
    long A, B, C, R;
    cin >> A >> B >> C >> R;

    for (int i = 2 ; i < N ; i++ ) 
        a[i] = (A * a[i - 2] + B * a[i - 1] + C) % R;
    cout << Find(a, N, K - 1);

    return 0;
}