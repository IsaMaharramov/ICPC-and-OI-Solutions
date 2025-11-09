#include<bits/stdc++.h>
using namespace std;

constexpr int sz = 2e5 + 5;

int n, q, a[sz], tree[2][sz];

inline void update(int pos, int val, int bj){
	
	while(pos <= n){
		
		tree[bj][pos] ^= val;
		
		pos += (pos & (-pos));
		
	}
	
	return;
}

inline int get_ans(int l, int r, int bj){
	if(l ^ 1) return get_ans(1, r, bj) ^ get_ans(1, l - 1, bj); 
	
	int res(0);
	
	while(r > 0){
		
		res ^= tree[bj][r];
		
		r -= (r & (-r));
		
		
	}
	
	return res;
	
}


signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
		update(i, a[i], i & 1);
	}	
	
	int type, l, r;
		
	while(q--){
		cin >> type >> l >> r;
		if(type == 1){
			
			update(l, a[l], l & 1);
			a[l] = r;
			update(l, a[l], l & 1);
			
		}else{
			
			if(~(r - l + 1) & 1){
				cout << 0 << '\n';
			}else{
				cout << get_ans(l, r, l & 1) << '\n';
			}
			
			
		}
		
	}
	
	
	
	
}