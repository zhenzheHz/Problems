#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int64_t k;
    cin >> k;
    int64_t tar = 1<<k;
    for(int i=1;i*i<tar;i++) {
        for(int j=1;i*i+j*j<tar;j++) {
            for(int k=1;i*i+j*j+k*k<tar;k++) {
                for(int l=1;i*i+j*j+k*k+l*l<=tar;l++) {
                    if(i*i+j*j+k*k+l*l == tar) {
                        vector<int> ans = {i,j,k,l};
                        sort(ans.begin(),ans.end());
                        for(int x=0;x<4;x++)
                            cout << ans[x] << " \n"[x==3];
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
}