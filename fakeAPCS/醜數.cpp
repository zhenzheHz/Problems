#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
    while(x%2 == 0) x /= 2;
    while(x%3 == 0) x /= 3;
    while(x%5 == 0) x /= 5;
    return x==1;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,i,now;
    cin >> n;
    for(i=1,now = 0;now<n;i++) {
        now += check(i);
    }
    cout << i-1 << '\n';
}