#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back

constexpr int sz = 200005;

int n, a[sz], fa[sz];

unordered_map<int, int> mp;

int op[sz], co(1), st[sz << 2], lazy[sz << 2];

inline void build(int l, int r, int in){
	if(l == r){
		st[in] = a[l];
		return;
	}
	int mid = l + ((r - l) >> 1);
	build(l, mid, in << 1);
	build(mid + 1, r, in << 1 | 1);
	st[in] = st[in << 1] + st[in << 1 | 1];
	return;
}

inline void relax(int l, int r, int in){
	if(l != r){
		lazy[in<<1] = lazy[in<<1|1] = lazy[in];
	}
	st[in] = lazy[in];
	lazy[in] = -1;
	return;
}


inline void update(int l, int r, int in, int L, int R, int val){
	if(lazy[in] != -1) relax(l, r, in);
	if(l > R || r < L) return;
	if(l >= L && r <= R){
		lazy[in] = val;
		relax(l, r, in);
		return;
	}
	int mid = l + ((r - l) >> 1);
	update(l, mid, in<<1, L, R, val);
	update(mid + 1, r, in<<1|1, L, R, val);
	st[in] = st[in<<1] + st[in<<1|1];
	return;
}

inline int get_ans(int l, int r, int in, int L, int R){
	if(lazy[in] != -1) relax(l, r, in);
	if(l>R || r<L) return 0;
	if(l >= L && r <= R) return st[in];
	int mid = l + ((r - l) >> 1);
	return get_ans(l, mid, in<<1, L, R) + get_ans(mid+1, r, in<<1|1, L, R);
}

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	memset(lazy, -1, sizeof(lazy));
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
		op[i] = a[i];
	}
	
	build(1, n, 1);
	
	for(register int i = 1; i <= n; ++i){
		
		if(get_ans(1, n, 1, mp[a[i]], mp[a[i]]) != a[i] || mp[a[i]] == 0){
			mp[a[i]] = i;
			continue;
		}
		
		//int r = i;
		
		update(1, n, 1, mp[a[i]], i, a[i]);
		
		//while(r >= mp[a[i]]){
		//	op[r--] = a[i];
		//}
		
		
		
		mp[a[i]] = i;
	}
	
	for(register int i = 1; i <= n; ++i){
		cout << get_ans(1, n, 1, i, i) << '\n';
	}
	
}