#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

constexpr int sz = 1001;

#define pii pair<int, int>
#define F first
#define S second

int timel;
int tin[sz];

vector<vector<int>> g;

int query(vector < int > islands);

inline void Dfs(int node, int fa = 1){
	tin[++timel] = node;
	for(auto &to : g[node]){
		if(to == fa) continue;
		Dfs(to, node);
	}
	return;
}

bool Query(int r){
	vector<int> v;
	for(register int i(1); i <= r; ++i) v.emplace_back(tin[i]);
	return query(v);
}

int findEgg(int N, vector < pair < int, int > > bridges){
	g.clear(), timel = 0;
	g.resize(N+1);
	for(register int i(0), a, b; i < N - 1; ++i){
		a = bridges[i].F, b = bridges[i].S;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	Dfs(1);
	int l = 1, r = N, mid, best(0);
	while(l < r){
		mid = l + ((r - l) >> 1);
		if(Query(mid)) r = mid;
		else l = mid + 1;
	}
	return tin[l];
}
