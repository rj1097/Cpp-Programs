#include <bits/stdc++.h>

using namespace std;

int distance(pair<int, int>& p)
{
    return p.first * p.first + p.second * p.second;
}

class compare {
public:
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        int distance1 = distance(p1);
        int distance2 = distance(p2);
        return distance1 < distance2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;
    vector<pair<int, int>> vec;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }
    cin >> k;
    while (n--) {
        auto currPt = vec.back();
        vec.pop_back();
        if (pq.size() < k) {
            pq.push(currPt);
        } else {
            pair<int, int> heapTop = pq.top();
            if (distance(currPt) < distance(heapTop)) {
                pq.pop();
                pq.push(currPt);
            }
        }
    }
    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    // while (!st.empty()) {
    //     cout << st.top().first << " " << st.top().second << endl;
    //     st.pop();
    // }
    return 0;
}
