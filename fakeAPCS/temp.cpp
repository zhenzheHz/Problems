#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,L;
vector<int> point[(int) 5e4+5];

int cut(int l,int r) {
	if(r - l <= 1) return 0;
	int mid = (point[l] + point[r]) / 2;
	int split = lower_bound(point.begin() + l,point.begin()+r, mid) - point.begin();
	if(point[split-1] > point[l] && mid - point[split-1] <= point[r] - mid) split--;
	return point[r]-point[l]+cut(l,split)+cut(split,r);
}

signed main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(0);
	cin >> n >> L;
	point[0] = 0, point[n+1] = L;
	cout << cut(0,n+1) << '\n';
}
