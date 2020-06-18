#include <bits/stdc++.h>

using namespace std;

bool compare(string& s1, string& s2)
{
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    // is s1 less than s2
    if (compare(s1, s2)) {
        cout << s1 << " is less than " << s2;
    } else {
        cout << s2 << " is less than " << s1;
    }
    return 0;
}