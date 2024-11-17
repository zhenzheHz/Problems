#include <bits/stdc++.h>
using namespace std;
void solve(int32_t n) {
    multiset<int64_t> ms;
    for(int i=0;i<n;i++) {
        int64_t x;
        cin >> x;
        ms.insert(x);
    }
    int64_t diff = 1e18,target;
    cin >> target;
    pair<int64_t,int64_t> ans;
    for(auto i = ms.begin();i!=ms.end();i = next(i)) {
        auto found = ms.upper_bound(target-*i);
        if(found == ms.begin() || prev(found) == i) continue;
        found = prev(found);
        if(*found != target-*i) continue;
        if(abs(*i-*found) < diff) diff = abs(*i-*found),ans = {*i,*found};
    }
    assert(ans.first <= ans.second);
    cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << ".\n\n";
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    while(cin >> n) {
        solve(n);
    }
}