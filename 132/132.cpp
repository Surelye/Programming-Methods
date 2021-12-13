#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void heapify(vector< pair<string, int> > &elts, int i)
{
    int left_child, right_child, 
        largest_child, heap_size = elts.size();

    for ( ; ; ) 
    {
        left_child = 2 * i + 1,
        right_child = 2 * i + 2;
        largest_child = i;

        if (left_child < heap_size && elts[left_child] > elts[largest_child])
            largest_child = left_child;

        if (right_child < heap_size && elts[right_child] > elts[largest_child])
            largest_child = right_child;

        if (largest_child == i)
            break;

        swap(elts[i], elts[largest_child]);
        i = largest_child;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int string_number, i;
    string placeholder;
    vector< pair<string, int> > elts;

    cin >> string_number;

    for (i = 0; i < string_number; ++i)
    {
        cin >> placeholder;
        elts.push_back(make_pair(placeholder, i + 1));
    }

    for (i = string_number / 2; i >= 0; --i)
        heapify(elts, i);
    
    //for (i = 0; i < string_number; ++i)
    //    cout << elts[i].first << " " << elts[i].second << endl;

    vector<int> result(string_number);

    for (i = 0; i < string_number; ++i)
        result[elts[i].second - 1] = i + 1;
        
    for (i = 0; i < string_number; ++i)
        cout << result[i] << " ";
    
    return 0;
}
