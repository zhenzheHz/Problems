// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://codeforces.com/contest/1990/problem/A
#include <bits/stdc++.h>
// #include <debug.h>
#define int int64_t
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(55,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }
    for(int i=1;i<=50;i++) {
        if(cnt[i] & 1) 
            return cout<<"Yes\n",void();
    }
    cout << "No\n";
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}