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
	array<vector<int>, 9> A;
	for(register int i = 0, a, b, t; i < N; ++i){
		cin >> t >> a >> b;
		if((a <= 4 && b <= 4) || (a > 4 && b > 4)) continue;
		A[a].emplace_back(t);
	}
	long long pinneapple(0), blueberry(0);
	for(register int i = 1; i <= 4; ++i){
		pinneapple += 1ll * 100 * (int)A[i].size();
		for(register int j = 1; j < (int)A[i].size(); ++j) if(A[i][j] - A[i][j-1] <= 10) pinneapple += 50;
	}
	for(register int i = 5; i <= 8; ++i){
		blueberry += 1ll * 100 * (int)A[i].size();
		for(register int j = 1; j < (int)A[i].size(); ++j) if(A[i][j] - A[i][j-1] <= 10) blueberry += 50;
	}
	cout << pinneapple << ' ' << blueberry << '\n';
	return 0;
}