#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 100005;

int n;
int d[sz];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	long long sm(0);
	int mn{(int)1e9 + 7};
	for(register int i = 1; i <= n; ++i){
		cin >> d[i];
		sm += d[i];
		mn = min(mn, d[i]);
	}
	sm += 1ll * (n - 2) * mn;
	cout << sm << '\n';
	return 0;
}