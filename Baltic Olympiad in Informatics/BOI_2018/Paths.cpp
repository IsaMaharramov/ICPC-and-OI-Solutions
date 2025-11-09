#include<bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define int long long

constexpr int sz = 3e5 + 5;
 
int n, m, k, ans, c[sz];
 
vector<int> g[sz];

int dp[sz][33];

int dfs(int node, int co){
	
	if(dp[node][co] != -1) return dp[node][co];
	
	dp[node][co] = (__builtin_popcount(co) > 1);
	
	for(auto &to : g[node]){
		if(co & (1 << c[to])) continue;
		
		
		dp[to][co | (1 << c[to])] = dfs(to, co | (1 << c[to]));
		
		
	}
	
	for(auto &to : g[node]){
		
		if(~co & (1 << c[to])) dp[node][co] += dp[to][co | (1 << c[to])];
		
	}
	
	return dp[node][co];	
}
 
 
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(register int i = 1; i <= n; ++i){
		cin >> c[i];
	//	c[i]--;
	}
	
	for(register int i = 1, u, v; i <= m; ++i){
		cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
	}
	
	memset(dp, -1, sizeof(dp));
	
	for(register int i = 1; i <= n; ++i){
		dp[i][1 << c[i]] = dfs(i, (1 << c[i]));
		ans += dp[i][1 << c[i]];
	}
	
	cout << ans << '\n';
	
	
	return 0;
}