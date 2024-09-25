#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x,tree[20000];
    cin >> x;
    memset(tree,-1,sizeof(tree));
    tree[1] = x;
    while(cin >> x) {
        int now_id = 1;
        while(tree[now_id] != -1) {
            if(x <= tree[now_id])
                now_id = now_id<<1;
            else
                now_id = now_id<<1|1;
        }
        tree[now_id] = x;
    }
    vector<int> h(1040,0);
    h[1] = 1;
    int ans = 1;
    function<void(int,int)> dfs=[&](int cur = 1,int from = 0) {
        if(cur!=1) h[cur] = h[from] + 1;
        ans = max(ans,h[cur]);
        if(tree[2*cur] != -1) dfs(2*cur,cur);
        if(tree[2*cur+1] != -1) dfs(2*cur+1,cur);
    };
    dfs(1,1);
    cout << ans << '\n';
}