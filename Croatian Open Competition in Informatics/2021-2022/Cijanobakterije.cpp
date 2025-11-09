#include<bits/stdc++.h>
using namespace std;

int n, m, mxnode, maxd;
vector<int> g[100001];
bool vis[100001];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1, u, v; i <= m; ++i){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	function<void(int, int, bool, int)> Dfs = [&](int node,int len, bool f, int fa){
		if(f) vis[node] = true;
		if(maxd < len){
			maxd = len, mxnode = node;
		}
		for(int &to : g[node]){
			if(vis[to] || to == fa) continue;
			Dfs(to, len + 1, f, node);
		}
		return;
	};
	int ans(0);
	for(register int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		maxd = 0;
		Dfs(i, 0, 0, i);
		Dfs(mxnode, 0, 1, mxnode);
		ans += maxd + 1;
	}
	cout << ans << '\n';
	return 0;
}