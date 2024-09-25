#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    cin >> n;
    int64_t ans = 0;
    vector<int64_t> arr(n);
    for(auto &i : arr) cin >> i;
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            int64_t result = 0;
            for(int i=l;i<=r;i++) {
                result += arr[i];
            }
            ans = max(ans,result);
        }
    }
    cout << ans << '\n';
}