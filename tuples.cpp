#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
    tuple<string, string, int> user;
    user = make_tuple("Rajat", "Jain", 23);
    cout << get<0>(user) << endl;
    cout << tuple_size<decltype(user)>::value << endl;
    vector<int> vec;
    vec.push_back(1);
    vector<int>::iterator itr = vec.begin() + 1;
    cout << *itr;
    return 0;
}