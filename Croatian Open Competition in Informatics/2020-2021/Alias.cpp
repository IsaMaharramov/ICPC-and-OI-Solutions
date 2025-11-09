#include<bits/stdc++.h>

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define file freopen("condense2.in", "r", stdin), freopen("condense2.out", "w", stdout);
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

const int sz = 1001;

int n, m, Q, cnt(1), t;
long long d[sz];
vector<array<int, 2>> g[sz];
string a, b;
map<string, int> mp;

priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;

inline void Dijkstra(int &s){
	q.push({s, 0});
	d[s] = 0;
	while(!q.empty()){
		int node = q.top().first;
		long long dist = q.top().second;
		q.pop();
		if(dist > d[node]) continue;
		for(auto &to : g[node]){
			int toto{to[0]}, len{to[1]};
			if(d[toto] > dist + len){
				d[toto] = dist + len;
				q.push({toto, d[toto]});
			}
		}
	}
	return;
}

inline void init(){
	for(register int i = 1; i <= n; ++i) d[i] = (int)(1e18);
	return;
}


int main(){
	speed;
	cin >> n >> m;
	for(register int i = 1, u, v; i <= m; ++i){
		cin >> a >> b >> t;;
		if(!mp[a]) mp[a] = cnt++;
		if(!mp[b]) mp[b] = cnt++;
		u = mp[a], v = mp[b];
		g[u].eb((array<int, 2>){v, t});
	}
	cin >> Q;
	while(Q--){
		cin >> a >> b;
		if(!mp[a]) mp[a] = cnt++;
		if(!mp[b]) mp[b] = cnt++;
		init();
		Dijkstra(mp[a]);
		if(d[mp[b]] == (int)1e18) cout << "Roger" << '\n';
		else cout << d[mp[b]] << '\n';
	}
	return 0;
}