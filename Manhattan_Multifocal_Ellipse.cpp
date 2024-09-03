// Author : Zhenzhe
// Time : 2024/09/03
// Problem : https://atcoder.jp/contests/abc366/tasks/abc366_e
// Class : Two Pointer, Brute Force
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
static constexpr int M = 2e6,N = 4e6+5;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    i32 n,d;
    cin >> n >> d;
    vector<i64> x(n),y(n),dis_x(N,0),dis_y(N,0);
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        x[i] += M, y[i] += M;
        dis_x[0] += x[i];
        dis_y[0] += y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=1,px=0,py=0;i<N;i++) {
        dis_x[i] = dis_x[i-1] + px - (n - px);
        dis_y[i] = dis_y[i-1] + py - (n - py);
        while(px<n && x[px]==i) px++;
        while(py<n && y[py]==i) py++;
    }
    sort(dis_x.begin(),dis_x.end());
    sort(dis_y.begin(),dis_y.end());
    i64 ans = 0;
    for(int i=0;i<N;i++) {
        if(dis_x[i] > d)continue;
        ans += upper_bound(dis_y.begin(),dis_y.end(),d-dis_x[i])-dis_y.begin();
    }
    cout << ans << '\n';
}