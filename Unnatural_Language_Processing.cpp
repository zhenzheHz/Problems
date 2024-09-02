// Author : Zhenzhe
// Time : 2024/07/19
// Problem : https://codeforces.com/contest/1915/problem/D
// Class : String , Syntax
#include <bits/stdc++.h>
#define int int64_t
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<string>ans;
    vector<bool> used(n,false);
    for(int i=n-1;i>=0;i--){
        if(used[i])continue;
        if(s[i]!='a'&&s[i]!='e')continue;
        string tmp="";
        tmp += s[i-1];used[i-1] = true;
        tmp += s[i];used[i] = true;
        if(i!=n-1&&!used[i+1])tmp+=s[i+1];
        ans.push_back(tmp);
    }
    reverse(all(ans));
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
        if(i!=ans.size()-1)cout<<'.';
    }
    cout << '\n';
}
int32_t main(){
    FASTIO;
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}
