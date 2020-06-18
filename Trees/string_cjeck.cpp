#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int n;
    cin >> n;
    str.append(to_string(n));
    str.push_back('a');
    str.push_back('a');
    cout << str;
    return 0;
}