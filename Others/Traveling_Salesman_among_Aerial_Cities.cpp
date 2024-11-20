// Author : Zhenzhe
// Time : 2024/09/04
// Problem : https://atcoder.jp/contests/abc180/tasks/abc180_e
// Class : Dynamic Programming
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
static constexpr i64 INF = 1e18+5;
i32 n;
i64 dp[20][1<<18],dis[20][20];
i64 get(i64 node,i64 status) {
    if(dp[node][status] != INF) return dp[node][status];
    i64 mn = INF;
    i32 pre_status = status - (1<<(n-node-1));
    for(int i=0;i<n;i++) {
        if(i == node) continue;
        mn = min(mn,get(i,pre_status)+dis[i][node]);
    }
    return dp[node][status] = mn;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    vector<i32> x(n),y(n),z(n);
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    memset(dp,INF,sizeof(dp));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]) + max(0,z[j]-z[i]);
        }
    }
    dp[0][1] = 0;
    cout << get(0,(1<<n)-1) << '\n';
}