#include <bits/stdc++.h>
using namespace std;
void tf(string tm,int &h,int &m,int &s) {
    h = (tm[0]-'0')*10 + (tm[1]-'0');
    m = (tm[3]-'0')*10 + (tm[4]-'0');
    s = (tm[6]-'0')*10 + (tm[7]-'0');
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    cin >> a >> b;
    int h1,h2,m1,m2,s1,s2;
    tf(a,h1,m1,s1);
    tf(b,h2,m2,s2);
    array<int,3> real = {h2-h1,m2-m1,s2-s1};
    for(int i=2;i>0;i--) {
        if(real[i] < 0) {
            real[i] += 60;
            real[i-1] -= 1;
        }
    }
    if(real[0]<0) real[0] += 24;
    string h,m,s;
    if(real[0] >= 10) h = to_string(real[0]);
    else h = '0' + to_string(real[0]);
    if(real[1] >= 10) m = to_string(real[1]);
    else m = '0' + to_string(real[1]);
    if(real[2] >= 10) s = to_string(real[2]);
    else s = '0' + to_string(real[2]);
    cout << h << ":" << m << ":" << s << '\n';
}