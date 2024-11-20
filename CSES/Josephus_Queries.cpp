// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Problem : https://cses.fi/problemset/task/2164
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int death(int n,int k) {
    if(k == 1) return 2;
    int tmp = death(n-1,k-1);
    return tmp>n? 
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--) {
        int n,k;
        cin >> n >> k;

    }
}