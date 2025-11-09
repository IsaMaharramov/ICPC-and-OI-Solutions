#include<bits/stdc++.h>

#define ld long double

using namespace std;

constexpr int sz = 1001;

int n;

array<int, 2> O[sz];

ld d[sz][sz];

ld get(int x1, int y1, int x2, int y2){
	return sqrtl((ld)(x1 - x2) * (x1 - x2) + (ld)(y1 - y2) * (y1 - y2));
}

inline void comp(){
	for(register int i = 1; i <= n; ++i){
		for(register int j = i; j <= n; ++j){
			d[i][j] = d[j][i] = get(O[i][0], O[i][1], O[j][0], O[j][1]);
		}
	}
	return;
}


int components, sizel[sz], fa[sz];


inline void init(){
	components = n;
	for(register int i = 1; i <= n; ++i) fa[i] = i, sizel[i] = 1;
	return;
}

int find_set(int v){
	if(v == fa[v]) return v;
	return fa[v] = find_set(fa[v]);
}

inline void Union(int a, int b){
	a = find_set(a), b = find_set(b);
	if(a ^ b){
		components--;
		if(sizel[a] > sizel[b]) swap(a, b);
		fa[a] = fa[b];
		sizel[b] += sizel[a];
	}
	return;
}

bool check(ld r){
	init();
	r *= 2;
	for(register int i = 1; i <= n; ++i){
		for(register int j = i; j <= n; ++j){
			if(r >= d[i][j]){
				Union(i, j);
			}
		}
	}
	return components == 1;
}

ld eps = 1e-6;


signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> O[i][0] >> O[i][1];
	}
	comp();
	ld l = 0, r = 1e9 + 10, mid, best;
	while(r - l >= eps){
		mid = (r + l) / 2;
		if(check(mid)){
			best = mid;
			r = mid;
		}else{
			l = mid;
		}
	}
	cout << fixed << setprecision(7) << best << '\n';
	return 0;
}