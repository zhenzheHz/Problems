// Author : Zhenzhe
// Time : 2024 / 10 / 25
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector<string> stand(n);
    for(auto &i : stand) cin >> i;
    for(int status = 0; status < (1<<n); status += 1) {
        vector<bool> check(m,false);
        int num = 0;
        for(int bit = 0; bit < n;bit += 1) {
            if((status >> bit) & 1) {
                num += 1;
                for(int index=0;index<m;index++) {
                    if(stand[bit][index] == 'o') {
                        check[index] = 1;
                    }
                }
            }
        }
        bool valid = 1;
        for(int x=0;x<m;x++) {
            if(!check[x]) {
                valid = false;
                break;
            }
        }
        if(valid) ans = min(ans,num);
    }
    cout << ans << '\n';
}