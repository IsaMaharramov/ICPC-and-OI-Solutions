#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(x) x.begin(), x.end()
#define int long long

constexpr int sz = 2e5 + 5;

int n, a[sz], pref[sz], suff[sz];

int ans = (int)1E18 + 7;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	
	for(register int i = 1; i <= n; ++i){
		pref[i] = pref[i-1] + max(0ll, a[i-1] - a[i] + 1);
	}
	
	for(register int i = n; i >= 1; --i){
		suff[i] = suff[i+1] + max(0ll, a[i+1] - a[i] + 1);
	}
	
	for(register int i = 1; i <= n; ++i){
		ans = min(ans, max(pref[i], suff[i]));
	}
	
	cout << ans << '\n';
	
	
}