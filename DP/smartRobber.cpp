#include <bits/stdc++.h>

using namespace std;

int sol(vector<int> vec)
{
    int* loot = new int[vec.size()];
    loot[0] = vec[0];
    if (vec.size() > 1) {
        loot[1] = max(vec[0], vec[1]);
        for (int i = 2; i < vec.size(); i++) {
            loot[i] = max(loot[i - 2] + vec[i], loot[i - 1]);
        }
    }
    return loot[vec.size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> houses(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> houses[i];
        }

        int maxAmt = sol(houses);
        cout << maxAmt;
    }
    return 0;
}