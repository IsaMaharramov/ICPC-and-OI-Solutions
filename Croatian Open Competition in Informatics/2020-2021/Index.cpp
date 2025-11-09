#include<bits/stdc++.h>

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define file freopen("condense2.in", "r", stdin), freopen("condense2.out", "w", stdout);
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

const int sz = 200005;

int n, Q, c[sz], tree[sz], ans[sz];

struct query{
	int l, r, index;
} q[sz];

bool cmp(query &a, query &b){
	if(a.l/316 != b.l/316) return a.l/316 < b.l/316;
	return a.r/316 < b.r/316;
}

inline void update(int pos, int val){
	while(pos <= n){
		tree[pos] += val;
		pos += (pos & (-pos));
	}
	return;
}

int get(int l, int r){
	if(l ^ 1) return get(1, r) - get(1, l - 1);
	int res(0);
	while(r > 0){
		res += tree[r];
		r -= (r & (-r));
	}
	return res;
}

inline void add(int x){
	update(x, 1);
	return;
}

inline void del(int x){
	update(x, -1);
	return;
}

int main(){
	speed;
	cin >> n >> Q;
	for(register int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	for(register int i = 1; i <= Q; ++i){
		cin >> q[i].l >> q[i].r, q[i].index = i;
	}
	sort(q+1,q+Q+1,cmp);
	int l(1), r(0);
	for(register int i = 1; i <= Q; ++i){
		while(r < q[i].r) add(c[++r]);
		while(r > q[i].r) del(c[r--]);
		while(l < q[i].l) del(c[l++]);
		while(l > q[i].l) add(c[--l]);
		int L(1), R{r - l + 1}, mid, best;
		while(L <= R){
			mid = L + ((R - L) >> 1);
			if(get(mid, n) >= mid){
				best = mid, L = mid + 1;
			}else{
				R = mid - 1;
			}
		}
		ans[q[i].index] = best;
	}
	for(register int i = 1; i <= Q; ++i){
		cout << ans[i] << '\n';
	}
	return 0;
}