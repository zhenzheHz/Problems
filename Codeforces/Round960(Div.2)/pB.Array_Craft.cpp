// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://codeforces.com/contest/1990/problem/B
#include <bits/stdc++.h>
// #include <debug.h>
#define int int64_t
using namespace std;
void solve() {
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> arr(n+1);
    for(int i=y;i<=x;i++)
        arr[i] = 1;
    for(int i=y-1,sign = -1;i>=1;i--,sign *= -1)
        arr[i] = sign;
    for(int i=x+1,sign = -1;i<=n;i++,sign *= -1)
        arr[i] = sign;
    for(int i=1;i<=n;i++) 
        cout << arr[i] << " \n"[i==n];
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}