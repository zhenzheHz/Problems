// Author : Zhenzhe
// Time : 2024 / 11 / 17
// Problem : https://cses.fi/problemset/task/2190
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using Point = pair<int,int>;
template<typename T>
Point operator-(pair<T,T> a,pair<T,T> b) {
    return make_pair(a.x-b.x,a.y-b.y);
}
template<typename T>
T cross(pair<T,T> a,pair<T,T> b) {
    return a.x*b.y-a.y*b.x;
}
int conv(int V) {
    return V>0? 1 : -1;
}
void solve() {
    Point a,b,c,d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    Point AB = a-b, AC = a-c, AD = a-d;
    Point CD = c-d, CA = c-a, CB = c-b;
    if(cross(AB,AC) >= 0 && cross(AB,AD) <= 0) {
        if(cross(CD,CA) * cross(CD,CB) <= 0)
            return cout<<"YES\n",void();
        // if(cross(CD,CA) <= 0 && cross(CD,CB) >= 0)
        //     return cout<<"YES\n",void();
    }
    else if(cross(AB,AC) <= 0 && cross(AB,AD) >= 0) {
        if(cross(CD,CA) >=0 * cross(CD,CB) <= 0)
            return cout<<"YES\n",void();
        // if(cross(CD,CA) <= 0 && cross(CD,CB) >= 0)
        //     return cout<<"YES\n",void();
    }
    else return cout << "NO\n",void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}