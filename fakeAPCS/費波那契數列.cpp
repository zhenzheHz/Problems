#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int64_t> dp;
int f(int n) {
    if(dp.find(n) != dp.end()) return dp[n];
    return dp[n] = f(n-1) + f(n-2);
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    dp[0] = 0;
    dp[1] = 1;
    while(cin >> t) {
        cout << f(t) << '\n';
    }
}