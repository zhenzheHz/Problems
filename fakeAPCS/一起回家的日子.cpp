#include <bits/stdc++.h>
using namespace std;
int month[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
int64_t gcd(int a,int b) {
    while(a%b !=0){
        int r = a%b;
        a = b;
        b = r; 
    }
    return b;
}
int64_t lcm(const int &a,const int &b) {
    int tmp = a*b;
    return tmp/gcd(a,b);
}
bool is_lean_year(int year) {
    if(year%4 == 0 && year%100 != 0)
        return 1;
    else if(year%400 == 0)
        return 1;
    else return 0;
}
void check(int y) {
    if(is_lean_year(y)) month[2] = 29;
    else month[2] = 28;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,next;
    cin >> n;
    cin >> next;
    int date[n];
    date[0] = next;
    for(int i=1;i<n;i++) {
        cin >> date[i];
        next = lcm(next,date[i]);
    }
    string now;cin>>now;
    int y,m,d;
    y = (now[0]-'0')*1000 + (now[1]-'0')*100 + (now[2]-'0')*10 + (now[3]-'0');
    m = (now[5]-'0')*10 + (now[6]-'0');
    d = (now[8]-'0')*10 + (now[9]-'0');
    d += next;
    check(y);
    while(d > month[m]) {
        check(y);
        d -= month[m];
        m += 1;
        if(m == 13) m = 1, y += 1; 
        check(y);
    }
    check(y);
    string yy,mm,dd;
    //d -= 1;
    if(d==0) {
        m -= 1;
        if(m == 0) {
            y -= 1;
            m = 12;
        }
        check(y);
        d = month[m];
    }
    yy = to_string(y);
    mm = to_string(m);
    dd = to_string(d);
    if(m < 10) mm = "0" + mm;
    if(d < 10) dd = "0" + dd;
    cout << yy << "/" << mm << "/" << dd << '\n';
}