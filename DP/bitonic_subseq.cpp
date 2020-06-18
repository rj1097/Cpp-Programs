#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void print_sol(const vector<int>& v)
{
    int size = v.size();
    vector<int> left(size, 1);
    vector<int> right(size, 1);
    left[0] = 1;
    for (int i = 1; i < size; i++) {
        int currMax = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                currMax = max(currMax, left[j]);
            }
        }
        left[i] += currMax;
    }

    right[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--) {
        int currMax = 0;
        for (int j = size - 1; j > i; j--) {
            if (v[i] > v[j]) {
                currMax = max(currMax, right[j]);
            }
        }
        right[i] += currMax;
    }
    int maxLen = INT_MIN;
    for (int i = 0; i < size; i++) {
        maxLen = max(maxLen, left[i] + right[i] - 1);
    }
    cout << maxLen << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        print_sol(vec);
    }
    return 0;
}