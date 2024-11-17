// Problem : Password Analyzer
// Label : ZeroJudge a624 / Codewars
// Tag : string
// Source : https://zerojudge.tw/ShowProblem?problemid=a624
#include <bits/stdc++.h>
using namespace std;
void inspect(string &str) {
    while(str.back() == '\n' || str.back() == '\r') str.pop_back();
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string password;
    while(getline(cin,password)) {
        inspect(password);
        int meet = 0;
        meet += (password.length() >= 8);
        bool upper = 0, lower = 0;
        bool alpha = 0, number = 0, sign = 0;
        for(auto ch : password) {
            if(isupper(ch)) upper = 1;
            if(islower(ch)) lower = 1;
            if(isalpha(ch)) alpha = 1;
            if(isdigit(ch)) number = 1;
            if(!isalpha(ch) && !isdigit(ch)) sign = 1;
        }
        meet += (upper && lower);
        meet += (alpha && (number || sign));
        cout << "This password is ";
        if(meet == 0) cout << "WEAK\n";
        else if(meet == 1) cout << "ACCEPTABLE\n";
        else if(meet == 2) cout << "GOOD\n";
        else cout << "STRONG\n";
    }
}