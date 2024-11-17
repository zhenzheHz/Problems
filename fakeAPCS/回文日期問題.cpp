#include <bits/stdc++.h>
using namespace std;
int month[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
bool check(string str) {
    string copy = str;
    reverse(copy.begin(),copy.end());
    return copy==str;
}
void solve() {
    string year;
    cin >> year;
    int tmp = stoi(year);
    bool is_leap_year = false;
    if(tmp%4 == 0 && tmp%100!=0) is_leap_year = true;
    if(tmp%400 == 0) is_leap_year = true;
    vector<string> ans;
    assert(ans.size()==0);
    for(int32_t mon = 1;mon<13;mon++) {
        string info = year;
        if(mon < 10) info.push_back('0');
        info = info + to_string(mon);
        for(int32_t j=1;j<=month[is_leap_year][mon];j++) {
            string tmp = info;
            if(j < 10) tmp.push_back('0');
            tmp = tmp + to_string(j);
            // cout << tmp << '\n';
            if(check(tmp)) ans.push_back(tmp);
        }
    }
    cout << ans.size() << " \n"[ans.size()==0];
    for(int32_t i=0;i<ans.size();i++) {
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    cin >> n;
    while(n--) {
        solve();
    }
}