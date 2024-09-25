#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void normal_move(int ring,char from,char to) {
    cout << "ring " << ring << " : " << from << " => " << to << '\n';
    cnt += 1;
}
void super_move(int n,char A,char B,char C) {
    if(n <= 0) return void();
    super_move(n-1,A,C,B);
    normal_move(n,A,C);
    super_move(n-1,B,A,C);
}
void distribute(int n,char A,char B,char C) {
    if(n <= 0) return void();
    super_move(n-1,A,C,B);
    normal_move(n,A,C);
    distribute(n-2,B,C,A);
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    distribute(n,'A','B','C');
    cout << "共需" << cnt << "個移動\n";
}