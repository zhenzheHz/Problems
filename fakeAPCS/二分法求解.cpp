#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    function<double(double)> f=[&](double x) {
        return 2 - exp(x);
    };
    double l = 0, r = 1.0;
    while(fabs(r-l) > 1e-8) {
        double m = (l+r)/2.0;
        if(f(m) <= 0) r = m;
        else l = m;
    }
    cout << fixed << setprecision(6) << l;
}