#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin >> n;
    // int minEl = INT_MAX;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        // minEl = min(minEl, vec[i]);
    }
    int minVal = *min_element(vec.begin(), vec.end());
    vector<int> res;
    for (int i = 0; i < n; i++) {
        auto maxElement = max_element(vec.begin(), vec.end() - i);
        int maxIdx = maxElement - vec.begin();
        if (minVal == *maxElement) {
            break;
        }

        res.push_back(maxIdx + 1);
        res.push_back(n - i);
        reverse(vec.begin(), maxElement + 1);
        reverse(vec.begin(), vec.end() - i);
    }

    for (int i : res) {
        cout << i << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}