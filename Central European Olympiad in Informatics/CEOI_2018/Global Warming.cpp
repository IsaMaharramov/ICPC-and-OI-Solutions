#include<bits/stdc++.h>
using namespace std;

constexpr int sz = 2e5 + 5;
constexpr int inf = 1E9 + 7;
 
int n, x, a[sz], f[sz], f2[sz], num, num2, p[sz], p2[sz], ans;
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> x;
	
	for(register int i = 1; i <= n; ++i) cin >> a[i];
	
	for(register int i = 1; i <= n; ++i){
		
		if(a[i] > f[num]){
			
			f[++num] = a[i];
			
			p[i] = num;
		
		}else{
			
			p[i] = lower_bound(f + 1, f + num + 1, a[i]) - f;
			
			f[p[i]] = a[i];
			
		}
		
	}
	
	f2[0] = inf;
	
	for(register int i = n; i >= 1; --i){
		
		p2[i] = lower_bound(f2 + 1, f2 + num2 + 1, a[i] - x, greater<int>()) - f2;
		
		if(a[i] < f2[num2]){
			
			f2[++num2] = a[i];
			
			p2[i] = num2;
		
		}else{
			
			*lower_bound(f2 + 1, f2 + num2 + 1, a[i], greater<int>()) = a[i];
			
			
		}
		
		
		
	}
	
	
	for(register int i = 1; i <= n; ++i) ans = max(ans, p[i] + p2[i] - 1);
	
	cout << ans << '\n';
	
	
	
	
}