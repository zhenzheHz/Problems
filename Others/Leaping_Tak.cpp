// Author : Zhenzhe
// Time : 2024/09/04
// Problem : https://atcoder.jp/contests/abc180/tasks/abc179_d
// Class : Greedy
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
static constexpr i32 N = 2e5+5;
i64 dp[N],n,k;
inline void update(i32 p,i64 v) {
    while(p<=n) {
        dp[p] += v;
        p += p&-p;
    }
}
inline i64 get(i32 p) {
    i64 sum = 0;
    while(p) {
        sum += dp[p];
        p -= p&-p;
    }
    return sum;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k;
    vector<pair<i32,i32>> seg(k);
    for(int i=0;i<k;i++) {
        cin >> seg[i].first >> seg[i].second;
    }
    dp[1] = 1;
    for(int i=1;i<=n;i++) {
        update(i-1,dp[i-1]);
        for(int j=0;j<k;j++) {
            auto [l,r] = seg[i];
            if(i + l <= n) update(i+l,dp[i]);
            if(i + r <= n) update(i+r+1,-dp[i]);
        }
    }
    cout << get(n) << '\n';
}