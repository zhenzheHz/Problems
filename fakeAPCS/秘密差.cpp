#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line;
    cin >> line;
    int32_t odd = 0,even = 0;
    for(int32_t i=0;i<line.size();i++) {
        odd += (line[i]-'0') * (i&1);
        even += (line[i]-'0') * (!(i&1));
    }
    cout << abs(odd-even) << '\n';
}