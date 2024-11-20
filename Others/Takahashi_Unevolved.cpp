// Author : Zhenzhe
// Time : 2024/09/03
// Problem : https://atcoder.jp/contests/abc180/tasks/abc180_d
// Class : Greedy
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
static constexpr i64 N = 2e18;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    i64 x,y,a,b;
    cin >> x >> y >> a >> b;
    i64 ans = 0;
    while((double)a*x <= N && a*x<=x+b && a*x < y) {
        ans++ ,x *= a;
    }
    cout << ans+(y-x-1)/b;
}