// Author : Zhenzhe
// Time : 2024/09/02
// Problem : https://atcoder.jp/contests/abc366/tasks/abc366_f
// Class : Dynamic Programming
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
#define a first
#define b second
using namespace std;
using pii = pair<i32,i32>;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    i32 n,k;
    cin >> n >> k;
    vector<pii> cfic(n);
    for(auto &[f,s] : cfic) {
        cin >> f >> s;
    }
    sort(cfic.begin(),cfic.end(),[&](const pii i,const pii j){
        return (i.a - 1) * j.b < (j.a - 1) * i.b;
    });
    vector<i64> dp(k+1,-1e9);
    dp[0] = 1;
    for(auto [a,b] : cfic) {
        vector<i64> tf = dp;
        for(int i=1;i<=k;i++) {
            if(dp[i-1] == -1e9)continue;
            tf[i] = max(tf[i], a*dp[i-1]+b);
        }
        dp = tf;
    }
    cout << dp[k] << '\n';
}