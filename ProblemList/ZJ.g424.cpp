// Problem : PF.抱ㄌㄌ
// Label : ZeroJudge g424
// Tag : dp + 單調隊列優化
// Source : https://zerojudge.tw/ShowProblem?problemid=g424
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
int arr[MAXN], dp[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, k, sum = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    deque<int> cur;
    memset(dp,0,sizeof(dp));
    cur.push_back(0);
    for(int i=1;i<=n;i++) {
        while(cur.front() < i-k-1) cur.pop_front();
        dp[i] = arr[i] + dp[cur.front()];
        while(cur.size() && dp[cur.back()] > dp[i]) cur.pop_back();
        cur.push_back(i);
    }
    while(cur.front() < n-k) cur.pop_front();
    cout << sum - dp[cur.front()] << '\n';
}