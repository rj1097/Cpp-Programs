#include <bits/stdc++.h>

using namespace std;

void printNums(int& nums)
{
    if (nums == 0) {
        return;
    }
    int nums2 = nums - 1;
    printNums(nums2);
    cout << nums << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    printNums(n);
    cout << n;
    return 0;
}