#include <bits/stdc++.h>
using namespace std;
int32_t n,k;
vector<int32_t> pos;
bool check(int32_t radius) {
    int64_t R = -1,count = 0;
    for(int i=0;i<n;i++) {
        if(R >= pos[i]) continue;
        count += 1;
        R = pos[i] + radius;
    }
    return count<=k;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int32_t x;
        cin >> x;
        pos.push_back(x);
    }
    sort(pos.begin(),pos.end());
    int l = 0, r = 1e9+1;
    while(l+1!=r) {
        int32_t m = (l+r)>>1;
        if(check(m)) r = m;
        else l = m;
    }
    cout << r << '\n';
}