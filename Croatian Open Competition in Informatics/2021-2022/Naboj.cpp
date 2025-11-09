#include<bits/stdc++.h>
using namespace std;

int n, m, cnt[200002];

vector<int> g[200002], em;

queue<int> q;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(register int i = 1, a, b; i <= m; ++i){
		cin >> a >> b;
		
		g[b].emplace_back(a);
		
		cnt[a]++;
	}
	
	for(register int i = 1; i <= n; ++i){
		if(!cnt[i]) q.push(i);
	}
	
	while(!q.empty()){
		
		int cur = q.front();
		q.pop();
		
		em.emplace_back(cur);
		
		for(const int &to : g[cur]){
			
			cnt[to]--;
			
			if(!cnt[to]) q.push(to);
			
		}
	}
	
	if((int)em.size() ^ n){
		cout << -1 << '\n';
	}else{
		cout << n << '\n';
		for(const int &to : em) cout << to << ' ' << 1 << '\n';
	}
	
	
	return 0;
}