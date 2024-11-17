#include <bits/stdc++.h>
using namespace std;
struct info {
    string animal,place;
    int32_t nums = 0;
};
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    cin >> n;
    vector<info> tmp(n);
    unordered_map<string,vector<info>> location;
    unordered_map<string,bool> used;
    for(int32_t i=0;i<n;i++) {
        string a,b;int32_t c;
        cin >> a >> c >> b;
        tmp[i] = {a,b,c};
        used[a] = false;
        bool found = false;
        for(int32_t ptr = 0;ptr < location[b].size();ptr++) {
            if(a == location[b][ptr].animal) {
                location[b][ptr].nums += c;
                found = true;
                break;
            }
        }
        if(!found) location[b].push_back({a,b,c});
    }
    for(int32_t i=0;i<n;i++) {
        if(used[tmp[i].place]) continue;
        used[tmp[i].place] = true;
        cout << tmp[i].place << ":";
        for(int32_t ptr = 0;ptr < location[tmp[i].place].size();ptr++) {
            cout << location[tmp[i].place][ptr].animal << ' ' <<  location[tmp[i].place][ptr].nums;
            cout << ",\n"[ptr == location[tmp[i].place].size()-1];
        }
    }
}