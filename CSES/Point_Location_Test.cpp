// Author : Zhenzhe
// Time : 2024 / 11 / 16
// Problem : https://cses.fi/problemset/task/2189
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using pnt = pair<int,int>;
template<typename T>
pnt operator-(pair<T,T> a,pair<T,T> b) {
    return make_pair(a.x-b.x,a.y-b.y);
}
template<typename T>
T cross(pair<T,T> a, pair<T,T> b) {
    return a.x*b.y-a.y*b.x;
}
void solve() {
    pnt a,b,c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    int nor = cross(b-a,c-a);
    if(nor == 0) cout << "TOUCH\n";
    else if(nor > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}