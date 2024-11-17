// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://codeforces.com/contest/1990/problem/C
#include <bits/stdc++.h>
// #include <debug.h>
#define int int64_t
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    map<int,int> current;
    pair<int,int> MAD = {0,0}; // times, max_value
    int ans = 0;
    for(int i=0;i<n;i++) {
        current[arr[i]] += 1;
        if(MAD.first == current[arr[i]])
            MAD.second = max(MAD.second, arr[i]);
        else if(MAD.first < current[arr[i]])
            MAD = {current[arr[i]], arr[i]};
        ans += current[arr[i]] * MAD.second;
        cout << current[arr[i]] << ' ' << MAD.second << '\n';
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}