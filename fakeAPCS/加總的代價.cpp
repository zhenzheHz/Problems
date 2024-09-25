#include <bits/stdc++.h>
using namespace std;
static constexpr int N = 5005;
inline void solve(int n) {
    priority_queue<int64_t,vector<int64_t>,greater<int64_t>> pq;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int64_t ans = 0;
    while(pq.size() > 1) {
        int64_t a = pq.top();pq.pop();
        int64_t b = pq.top();pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    while(cin >> n) {
        if(n == 0) break;
        solve(n);
    }
}