#include<bits/stdc++.h>

using namespace std;

constexpr int sz = 1e5 + 6;

int n, a[sz];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	
	int ans = (int)(1e9 + 7);
	for(register int i = 1; i <= n; ++i){
		int l = i - 1, r = i + 1, mn = (int)(1e9);
		while(l || r <= n){
			if(a[l] > a[i]) l = 0;
			if(a[r] > a[i]) r = n + 1;
			if(l && r <= n){
				if(a[l] > a[r]){
					mn = min(mn, a[l]);
					ans = min(ans, a[i] - mn);
			        --l;
				}else{
					mn = min(mn, a[r]);
					ans = min(ans, a[i] - mn);
					++r;
				}
			}else if(l){
				mn = min(mn, a[l]);
			    ans = min(ans, a[i] - mn);
			    --l;
		    }else if(r <= n){
		    	mn = min(mn, a[r]);
		    	ans = min(ans, a[i] - mn);
		    	++r;
			}else{
				break;
			}
		}
	//	cout << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
	
	
}