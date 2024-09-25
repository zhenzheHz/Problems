#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int grade[25];
    set<int> pass,fail;
    for(int i=0;i<n;i++) {
        cin >> grade[i];
        if(grade[i] >=60) pass.insert(grade[i]);
        else fail.insert(grade[i]);
    }
    sort(grade,grade+n);
    for(int i=0;i<n;i++) cout << grade[i] << " \n"[i==n-1];
    if(fail.empty()) cout << "best case\n";
    else cout << *fail.rbegin() << '\n';
    if(pass.empty()) cout << "worst case\n";
    else cout << *pass.begin() << '\n';
}