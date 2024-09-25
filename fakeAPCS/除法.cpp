#include <bits/stdc++.h>
using namespace std;
void solve(int32_t n) {
    int32_t digit[] = {0,1,2,3,4,5,6,7,8,9};
    bool solutions = false;
    do{
        if(digit[0] >= 5) break;;
        int32_t b = 10000*digit[0]+1000*digit[1]+100*digit[2]+10*digit[3]+digit[4];
        int32_t a = 10000*digit[5]+1000*digit[6]+100*digit[7]+10*digit[8]+digit[9];
        if(a%b == 0 && a/b == n) {
            solutions = true;
            for(int32_t i=5;i<10;i++)cout<<digit[i];
            cout << " / ";
            for(int32_t i=0;i<5;i++)cout<<digit[i];
            cout << " = " << n;
            cout << '\n';
        }
    }while(next_permutation(digit,digit+10));
    if(!solutions) cout << "There are no solutions for " << n <<".\n";
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    while(cin >> n) {
        if(n == 0) break;
        solve(n);
    }
}