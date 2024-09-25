#include <bits/stdc++.h>
using namespace std;
using number = vector<int>;

number operator+(const number &a,const number &b) {
    number x = a,y = b;
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    if(x.size() < y.size())swap(x,y);
    number result(x.size()+2,{0});
    for(int i=0;i<x.size();i++) {
        if(i<y.size())
            result[i] += x[i] + y[i];
        else
            result[i] += x[i];
        if(result[i] > 9) {
            result[i+1] = (int)result[i]/10;
            result[i] %= 10;
        }
        //cout << result[i];
    }
    while(result.back() == 0) result.pop_back();
    reverse(result.begin(),result.end());
    return result;
}

void operator<<(ostream& o,number &k) {
    for(int i=0;i<k.size();i++) {
        o << k[i];
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<number> dp(125,{0});
    dp[1] = {1};
    for(int i=2;i<=n;i++) {
        for(int k=0;k<4;k++) {
            dp[i] = dp[i] + dp[i-1];
        }
    }
    number ans = {0};
    for(int i=1;i<=n;i++) {
        ans = dp[i] + ans;
    }
    cout << ans;
}