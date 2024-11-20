// Author : Zhenzhe
// Time : 2024/09/02
// Problem : https://atcoder.jp/contests/abc366/tasks/abc366_c
// Class : STL
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t q;
    cin >> q;
    map<int32_t,int32_t> cnt;
    while(q--){
        int op,tar;
        cin >> op;
        if(op == 1){
            cin >> tar;
            cnt[tar] += 1;
        }else if(op == 2){
            cin >> tar;
            if(--cnt[tar] == 0)
                cnt.erase(tar);
        }else{
            cout << cnt.size() << '\n';
        }
    }
}