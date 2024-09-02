// Author : Zhenzhe
// Time : 2024/09/02
// Problem : https://atcoder.jp/contests/abc366/tasks/abc366_a
// Class : Syntax,Greedy
#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n,a,b;
    cin >> n >> a >> b;
    int32_t rest = n-a-b;
    if(a < b) swap(a,b);
    cout << ((b + rest > a)? "No\n" : "Yes\n");
}