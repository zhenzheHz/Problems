// Author : Zhenzhe
// Time : 2024/09/03
// Problem : https://atcoder.jp/contests/abc180/tasks/abc180_c
// Class : STL,Math Theory
#include <bits/stdc++.h>
#define i32 int32_t
#define i64 int64_t
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    i64 n;
    cin >> n;
    set<long> factors;
    for(i64 i=1;i*i<=n;i++) {
        if(n%i == 0) {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    for(auto factor : factors) cout << factor << '\n';
}