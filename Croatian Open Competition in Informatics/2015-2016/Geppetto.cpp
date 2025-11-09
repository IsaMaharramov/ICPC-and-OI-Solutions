#include<bits/stdc++.h>
using namespace std;

int n, m, ans;

vector<int> tmp;

unordered_map<int, bool> mp[22];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1, u, v; i <= m; ++i){
		cin >> u >> v;
		mp[u][v] = true, mp[v][u] = true;
	}
	for(register int mask = 0; mask < (1 << n); ++mask){
		tmp.clear();
		for(register int i = 1; i <= n; ++i){
			if(mask & (1 << (i - 1))) tmp.emplace_back(i);
		}
		bool flag = true;
		
		for(register int i = 0; i < (int)tmp.size(); ++i){
			for(register int j = i + 1; j < (int)tmp.size(); ++j){
				flag &= !mp[tmp[i]][tmp[j]];
			}
		}
		
		
		ans += flag;
		
	}
	cout << ans << '\n';
	return 0;
}