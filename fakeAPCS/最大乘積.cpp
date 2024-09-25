#include <bits/stdc++.h>
using namespace std;
void solve(int32_t Case,int32_t n) {
    vector<int64_t> arr(n+1),dp(n+1,1);
    for(int32_t i=1;i<=n;i++) cin >> arr[i];
    // for(int32_t i = 1;i <= n;i++)
    //     dp[i] = dp[i-1] * arr[i];
    int64_t ans = 0;
    for(int32_t l=1;l<=n;l++) {
        for(int32_t r=l;r<=n;r++) {
            int64_t result = 1;
            for(int32_t i=l;i<=r;i++) {
                result *= arr[i];
            }
            ans = max(ans,result);
        }
    }
    cout << "Case #" << Case << ": The maximum product is " << ans << ".\n\n";
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n,Case = 1;
    while(cin >> n) {
        //if(n == 0) break;
        solve(Case++,n);
    }
}