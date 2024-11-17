// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://cses.fi/problemset/task/2191
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> points(n);
    for(auto &pnt : points) 
        cin >> pnt.first >> pnt.second;
    points.push_back(points.front());
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += points[i].first*points[i+1].second;
        ans -= points[i].second*points[i+1].first;
    }
    cout << abs(ans) << '\n';
}