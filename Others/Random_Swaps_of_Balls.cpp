// Author : Zhenzhe
// Time : 2024/09/05
// Probelm : https://atcoder.jp/contests/abc360/tasks/abc360_e
// Class : Dynamic Programming
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 998244353;
using matrix = vector<vector<int>>;
 
matrix operator*(const matrix &a,const matrix &b) {
    matrix c(a.size(),vector<int>(b[0].size(),0));
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b[0].size();j++) {
            for(int k=0;k<b.size();k++) {
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
 
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b&1) return (a*fp(a,b-1))%mod;
    int f = fp(a,b>>1);
    return (f*f)%mod;
}
 
int inv(int x) {
    return fp(x,mod-2)%mod;
}
 
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k,ans = 0;
    cin >> n >> k;
    int N2 = (inv(n*n))%mod;
    matrix T,S;
    // T = {
    //     {(((n-1)*(n-1)+1+mod*10)%mod)*N2%mod,2*N2%mod},
    //     {((2*n-2)*N2)%mod,(1-2*N2+mod*10)%mod},
    // };
    T = {
        {((n-1)*(n-1)+1+mod)%mod *N2 %mod,2*N2%mod},
        {(2*n-2)%mod*N2%mod,(n*n - 2)%mod *N2 %mod},
    };
    S = {
        {1,0},
        {0,1}
    };
    while(k) {
        if(k & 1) S = T * S;
        T = T * T;
        k >>= 1;
    }
    assert(N2 >= 0);
    assert(S[0][0] >= 0);
    assert(S[0][1] >= 0);
    ans += (S[0][0]%mod);
    ans += ((n+2)*(n-1)%mod*inv(2) %mod * S[0][1])%mod;
    cout << ans%mod << '\n';
    return 0;
}