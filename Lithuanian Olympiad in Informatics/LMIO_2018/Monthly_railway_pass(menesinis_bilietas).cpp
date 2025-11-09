#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

constexpr int sz = 500000;

int sizel[sz], fa[sz], N, M;

int find_set(int v){
	if(fa[v] == v)
	    return v;
	return fa[v] = find_set(fa[v]);
}

inline void Union(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if(x ^ y){
		if(sizel[x] > sizel[y]) swap(x, y);
		fa[x] = fa[y];
		sizel[y] += sizel[x];
    }
    return;
}

inline void init(){
	for(register int i = 1; i <= N; ++i) sizel[i] = 1, fa[i] = i;
	return;
}

string ch;

vector<pair<int, int>> laaa;

unordered_set<int> adj[sz];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	init();
	for(register int i = 1, x, y; i <= M; ++i){
		cin >> x >> y >> ch;
		if(ch[0] == 'T'){
			Union(x, y);
		}else{
			laaa.emplace_back((pair<int, int>){x, y});
		}
	}
	vector<int> A;
	for(register int i = 1; i <= N; ++i){
		if(find_set(i) == i) A.emplace_back(i);
	}
	for(register int i = 0; i < (int)laaa.size(); ++i){
		int x{laaa[i].first}, y{laaa[i].second};
		x = find_set(x), y = find_set(y);
		if(x == y) continue;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	int components{(int)A.size()}, ans(0);
	for(register int i = 0; i < components; ++i){
		if((int)adj[A[i]].size() == components - 1) ans += sizel[A[i]];
	}
	cout << ans << '\n';
	return 0;
}