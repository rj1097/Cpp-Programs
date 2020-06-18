#include <bits/stdc++.h>
using namespace std;

int max_bitonic_array_size(const vector<int>& vec)
{
    int size = vec.size();
    vector<int> maxArr(size, 1);
    vector<int> minArr(size, 1);

    for (int i = 1; i < size; i++) {
        if (vec[i] > vec[i - 1]) {
            maxArr[i] += maxArr[i - 1];
        }
    }

    for (int i = size - 2; i >= 0; i--) {
        if (vec[i] > vec[i + 1]) {
            minArr[i] += minArr[i + 1];
        }
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < size; i++) {
        int currVal = maxArr[i] + minArr[i];
        maxVal = max(maxVal, currVal);
    }
    return maxVal - 1;
}
int main()
{
    int t;
    cin >> t;
    vector<int> res;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        int sol = max_bitonic_array_size(vec);
        res.push_back(sol);
    }
    for (int val : res) {
        cout << val << endl;
    }
    return 0;
}