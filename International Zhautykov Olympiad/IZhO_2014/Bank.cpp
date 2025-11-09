#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> people(N), money(M);
	for(register int i = 0; i < N; ++i) cin >> people[i];
	for(register int i = 0; i < M; ++i) cin >> money[i];
	vector<pii> dp(1 << M);
	dp[0] = {0, 0};
	pii temp;
	bool flag{false};
	for(register int mask = 0; mask < (1 << M); ++mask){
		if(dp[mask].f == N){ flag = true; break;}
		for(register int j = 0; j < M; ++j){
			if(mask & (1 << j)) continue;
			if(dp[mask].s + money[j] == people[dp[mask].f]){
				temp = {dp[mask].f + 1, 0};
			}else{
				temp = {dp[mask].f, dp[mask].s + money[j]};
			}
			dp[mask | (1 << j)] = max(dp[mask | (1 << j)], temp);
		}
	}
	cout << (flag ? "YES" : "NO") << '\n';
	return 0;
}