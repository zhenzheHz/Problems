// Author : Zhenzhe
// Time : 2024/09/03
// Problem : https://atcoder.jp/contests/abc180/tasks/abc180_a
// Class : Syntax,Float
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    i32 n;
    cin >> n;
    i64 m = 0, h = 0, c = 0;
    for(int i=0;i<n;i++) {
        i64 node;
        cin >> node;
        m += abs(node);
        h += node*node;
        c = max(c,abs(node));
    }
    double H = sqrt(h);
    cout << m << '\n';
    cout << fixed << setprecision(10) << H << '\n';
    cout << c << '\n';
}