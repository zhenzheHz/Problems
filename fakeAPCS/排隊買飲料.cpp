#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n,k;
    cin >> n >> k;
    priority_queue<int64_t,vector<int64_t>,greater<int64_t>> pq;
    for(int i=0;i<k;i++) pq.push(0);
    for(int32_t i=0;i<n;i++) {
        int x;cin>>x;
        int64_t tmp = pq.top() + x;
        pq.pop();
        pq.push(tmp);
    }
    int64_t ans = 0;
    while(pq.size()) {
        ans = max(ans,pq.top());
        pq.pop();
    }
    cout << ans << '\n';
}