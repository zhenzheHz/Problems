// Author : Zhenzhe
// Time : 2024 / 10 / 25
#include <bits/stdc++.h> 
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m,check = 0;
    cin >> n >> m;
    vector<int> demand(m);
    multiset<int> price;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        price.insert(x);
    }
    for(int &i : demand) cin >> i;
    sort(demand.begin(),demand.end());
    int cost = 0;
    for(int i=0;i<m;i++) {
        auto found = price.lower_bound(demand[i]);
        if(found == price.end()) return cout<<-1<<'\n',0;
        cost += *found;
        price.erase(found);
    }
    cout << cost << '\n';
}