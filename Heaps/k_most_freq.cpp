#include <bits/stdc++.h>

using namespace std;

class compare {
public:
    bool operator()(pair<int, string>& w1, pair<int, string>& w2)
    {
        if (w1.first != w2.first) {
            return w1.first > w2.first;
        } else {
            string s1 = w1.second, s2 = w2.second;
            int size = min(s1.size(), s2.size());
            bool ans = true;
            for (int i = 0; i < size; i++) {
                if (s1[i] > s2[i]) {
                    ans = false;
                    break;
                } else if (s1[i] == s2[i]) {
                    ans = ans && (s1.size() < s2.size());
                }
            }
            return ans;
        }
        // return w1.second < w2.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    unordered_map<string, int> dict;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (dict.count(str) == 0) {
            dict[str] = 1;
        } else {
            dict[str] += 1;
        }
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
    for (auto word : dict) {
        if (pq.size() < k) {
            pq.push(make_pair(word.second, word.first));
            // cout << "dict word: " << word.first << "and heap top: " << pq.top().second << endl;
        } else {
            // cout << "dict word: " << word.first << "and heap top: " << pq.top().second << endl;
            int heapTopFreq = pq.top().first;
            int currWordFreq = word.second;
            if (heapTopFreq < currWordFreq) {
                cout << "Is less !!" << endl;
                pq.pop();
                pq.push(make_pair(word.second, word.first));
            } else if (heapTopFreq == currWordFreq) {
                cout << "Is equal !!" << endl;
                string s1 = word.first, s2 = pq.top().second;
                cout << "Word:" << s1 << " and string: " << s2 << endl;
                bool isWordSmall = (s1 < s2) && (s1.size() < s2.size());
                int size = min(s1.size(), s2.size());
                bool ans = true;
                for (int i = 0; i < size; i++) {
                    if (s1[i] > s2[i]) {
                        ans = false;
                        break;
                    } else if (s1[i] == s2[i]) {
                        ans = ans && (s1.size() < s2.size());
                    }
                }
                if (ans == true) {
                    pq.pop();
                    pq.push(make_pair(word.second, word.first));
                }
            }
        }
    }
    vector<string> res;
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());

    for (string word : res) {
        cout << word << " ";
    }
    return 0;
}