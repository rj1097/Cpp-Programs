#include <climits>
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> h;
    int x;
    cin >> x;
    h.push(x);
    while (--n) {
        cin >> x;
        if (h.size() < k) {
            h.push(x);
        } else {
            if (x > h.top()) {
                h.pop();
                h.push(x);
            }
        }
    }
    cout << h.top();
    return 0;
}
