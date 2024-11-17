#include <bits/stdc++.h>
using namespace std;
static constexpr int32_t N = 1e4+5;
int arr[N];
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n,target;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> target;
    int32_t left = -1,right = n;
    int32_t times = 0;
    while(left + 1 != right) {
        times += 1;
        int32_t mid = (left+right)>>1;
        if(arr[mid] == target) 
            return cout<<mid<<' '<<times,0;
        if(arr[mid] < target) left = mid;
        else right = mid;
    }
    if(arr[left] == target) cout << left;
    else cout << "not found";
    cout << ' ' << times;
}