// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://cses.fi/problemset/task/2195
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename T>
pair<T,T> operator-(pair<T,T> &a,pair<T,T> &b) {
    return make_pair(a.first-b.first,a.second-b.second);
}
template<typename T>
T cross(pair<T,T> a, pair<T,T> b) {
    return a.first*b.second-a.second*b.first;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> point(n),hull;
    for(auto &pnt : point) cin >> pnt.first >> pnt.second;
    sort(point.begin(),point.end());
    for(int i=0;i<2;i++) {
        int t = hull.size();
        for(auto pnt : point) {
            while(hull.size()-t>=2 && cross(hull.back()-hull[hull.size()-2],pnt-hull[hull.size()-2])<0)
                hull.pop_back();
            hull.push_back(pnt);
        }
        hull.pop_back();
        reverse(point.begin(),point.end());
    }
    cout << hull.size() << '\n';
    for(auto pnt : hull) {
        cout << pnt.first << ' ' << pnt.second << '\n';
    }
}