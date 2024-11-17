#include <bits/stdc++.h>
using namespace std;
inline int64_t solve() {
    string prompt;
    cin >> prompt;
    if(prompt == "END_IF") return 1;
    if(prompt == "ENDPROGRAM") return 0;
    if(prompt == "S") return solve();
    if(prompt == "IF") {
        
    }
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int64_t n;
    cin >> n;
    while(n--) {
        solve();
    }
}