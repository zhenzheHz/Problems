// Author : Zhenzhe
// Time : 2024 / 11 / 17
// Problem : https://cses.fi/problemset/task/2192
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using point = pair<int,int>;
point operator-(point a,point b) {
    return make_pair(a.x-b.x,a.y-b.y);
}
int cross(point a,point b) {
    return abs(a.x*b.y-a.y*b.x);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<point> pnts(n);
    for(auto &c : pnts) {
        cin >> c.x >> c.y;
    }
    pnts.push_back(pnts.front());
    int area = 0;
    for(int i=0;i<n;i++) {
        // cout << pnts[i].x << ' ' << pnts[i].y << '\n';
        area += pnts[i].x * pnts[i+1].y;
        area -= pnts[i].y * pnts[i+1].x;
    }
    // cout << area << '\n';
    while(m--) {
        point qry;
        cin >> qry.x >> qry.y;
        int now = 0,isprint = 0;
        for(int i=0;i<n;i++) {
            int s = cross(pnts[i]-qry,pnts[i+1]-qry);
            if(s == 0) {
                cout << "BOUNDARY\n";
                isprint = 1;
                break;
            }
            now += s;
        }
        if(!isprint) cout << (now == area? "INSIDE\n" : "OUTSIDE\n");
    }
}