#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	map<int, int> X, Y;
	vector<pair<int, int>> A(N);
	for(register int i = 0; i < N; ++i){
		cin >> A[i].first >> A[i].second;
		X[A[i].first]++, Y[A[i].second]++;
	}
	long long ans(0);
	for(register int i = 0; i < N; ++i){
		ans += 1ll * (X[A[i].first] - 1) * (Y[A[i].second] - 1);
	}
	cout << ans << '\n';
	return 0;
}