#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> k >> n;
    vector<vector<int>> v;
    for (int i = 0; i < k; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            pq.push(v[j][i]);
        }
        res.push_back(pq.top());
        pq.pop();
    }
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}