#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    unordered_map<char, int> freq_mp;
    for (char ch : str) {
        if (freq_mp.count(ch) == 0) {
            freq_mp[ch] = 1;
        } else {
            freq_mp[ch] += 1;
        }
    }

    priority_queue<pair<int, char>> max_heap;
    for (auto node : freq_mp) {
        // cout << node.first << ": " << node.second << endl;
        max_heap.push(make_pair(node.second, node.first));
    }
    // cout << endl;
    string res = "";
    while (!max_heap.empty()) {
        // cout << max_heap.top().first << ": " << max_heap.top().second << endl;
        // max_heap.pop();
        if (max_heap.size() >= 2) {
            auto p1 = max_heap.top();
            max_heap.pop();
            auto p2 = max_heap.top();
            max_heap.pop();
            res += p1.second;
            res += p2.second;
            p1.first--;
            p2.first--;
            if (p1.first > 0) {
                max_heap.push(p1);
            }

            if (p2.first > 0) {
                max_heap.push(p2);
            }
        } else if (max_heap.size() == 1) {
            auto p = max_heap.top();
            max_heap.pop();
            if (p.first > 1) {
                res = "";
            } else {
                res += p.second;
                p.first--;
            }
        }
    }
    cout << res;
    return 0;
}