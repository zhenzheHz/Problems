#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> dp;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    for(int i=1;i<=100000;i++) {
        int64_t k = i*i;
        string s = to_string(k);
        bool check = 1;
        for(char c : s) {
            if(c == '0' || c == '2' || c == '4' || c == '6' || c == '8') continue;
            check = 0;
            break;
        }
        if(dp.find(s.size()) == dp.end() && check)
            dp[s.size()] = k;
    }
    int t = 1;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        cout << dp[k] << '\n';
    }
}