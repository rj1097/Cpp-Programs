#include <iostream>
#include <vector>
using namespace std;

// Boyre Moore majority vote algorithm

vector<int> max_freq(const vector<int>& vec)
{
    vector<int> res;
    int num1 = vec[0], num2 = 0;
    int count1 = 0, count2 = 0;
    for (int val : vec) {
        if (val == num1) {
            count1++;
        } else if (val == num2) {
            count2++;
        } else if (count1 == 0) {
            num1 = val;
            count1 = 1;
        } else if (count2 == 0) {
            num2 = val;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int val : vec) {
        if (val == num1) {
            count1++;
        } else if (val == num2) {
            count2++;
        }
    }
    if (count1 > vec.size() / 3) {
        res.push_back(num1);
    }
    if (count2 > vec.size() / 3) {
        res.push_back(num2);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> res = max_freq(vec);
    if (res.size() == 0) {
        cout << "No Majority Elements";
    } else {
        for (int i : res) {
            cout << i << " ";
        }
    }
}