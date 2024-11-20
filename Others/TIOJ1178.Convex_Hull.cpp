// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problrm : https://tioj.ck.tp.edu.tw/problems/1178
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
template<typename T>
pair<T,T> operator-(pair<T,T> a,pair<T,T> b) {
    return make_pair(b.first-a.first,b.second-a.second);
}
template<typename T>
T cross(pair<T,T> a,pair<T,T> b) {
    return a.first*b.second - a.second*b.first;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> point(n),hull;
    for(int i=0;i<n;i++) {
        cin >> point[i].first >> point[i].second;
    }
    sort(point.begin(), point.end());
    for(int i=0;i<2;i++) {
        int t = hull.size();
        for(pair<int,int> &pnt : point) {
            while(hull.size()-t>=2 && cross(hull[hull.size()-2]-hull.back(),hull[hull.size()-2]-pnt)<=0) {
                hull.pop_back();
            }
            hull.push_back(pnt);
        }
        hull.pop_back();
        reverse(point.begin(),point.end());
    }
    cout << hull.size() << '\n';
}