#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> k >> n;
    vector<list<int>> l;
    for (int i = 0; i < k; i++) {
        list<int> currList;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            currList.push_back(x);
        }
        l.push_back(currList);
    }
    list<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            pq.push(l[j].front());
            l[j].pop_front();
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