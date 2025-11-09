#include<bits/stdc++.h>
using namespace std;

#define int long long

constexpr int sz = 2e5 + 5;

int n, a[sz], Q, x;

vector<array<int, 2>> em;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	
	for(register int i = 1; i <= n; ++i){
		long long cnt(1);
		while(a[i] % 2 == 0){
			cnt <<= 1LL;
			a[i] >>= 1LL;
		}
		em.emplace_back(array<int, 2>{cnt, a[i]});
	}
	int sm(0), l(-1);
	cin >> Q;
	while(Q--){
		cin >> x;
		while(sm < x){
			++l, sm += em[l][0];
		}
		cout << em[l][1] << '\n';
	}
	return 0;
}