// Author : Zhenzhe
// Time : 2024 / 10 / 25
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, take, arrival[105],ans[105];
    cin >> n >> take;
    for(int i=0;i<n;i++) {
        cin >> arrival[i];
    }
    ans[0] = arrival[0] + take;
    for(int i=1;i<n;i++) {
        if(ans[i-1] <= arrival[i]) {
            ans[i] = arrival[i] + take;
        }else {
            ans[i] = ans[i-1] + take;
        }
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << '\n';
    }
}