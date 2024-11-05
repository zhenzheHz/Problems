// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=e595
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void Convert(string &test) {
    int left = 0, right = test.size() - 1;
        string complement = "";
        while(left < right) {
        if(test[left] == test[right]) {
            left++, right--;
        }else {
            complement.push_back(test[left]);
            left++;
        }
    }
    reverse(complement.begin(),complement.end());
    test = test + complement;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string test;
    while(cin >> test) {
        string tmp(test.rbegin(),test.rend());
        while(test != tmp) {
            Convert(test);
            tmp = string(test.rbegin(),test.rend());
        }
        cout << test << '\n';
    } 
}