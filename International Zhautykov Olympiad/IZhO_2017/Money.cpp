#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(x) begin(x),end(x)

constexpr int sz = 1e6 + 6;

int n, a[sz];

set<int> st;

inline bool felo(int l, int r){
	
	auto it = st.upper_bound(l);
	
	if(it != st.end() && *it < r) return false;
	
	
	return true;
	
}

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	
	int l, ans(0);
	
	for(register int i = 1; i <= n; ++i){
		
		l = i;
		
		int mn = a[i];
		
		while((i ^ n) && a[i] <= a[i+1] && felo(mn, a[i+1])) ++i;
		
		++ans;
		
		for(register int j = l; j <= i; ++j) st.insert(a[j]);
		
		
	}
	
	
	cout << ans << '\n';
	
	
	return 0;
}