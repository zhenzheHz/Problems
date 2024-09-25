#include <bits/stdc++.h>
using namespace std;
int64_t f91(int64_t x) {
    if(x <= 100) return f91(f91(x+11));
    else return x - 10;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        if(n==0)break;
        cout << "f91(" << n << ") = " << f91(n) << '\n';
    }
}