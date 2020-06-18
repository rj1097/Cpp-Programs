#include <bits/stdc++.h>

using namespace std;

int sol(int n)
{
    int* arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ways = sol(n);
    cout << ways;
    return 0;
}