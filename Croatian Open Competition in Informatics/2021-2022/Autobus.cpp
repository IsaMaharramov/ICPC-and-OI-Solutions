#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 1e5 + 53243;
constexpr int inf = 1e9 + 7;

int n, m, K, Q;

int dp[100][100][100];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= 71; ++i){
		for(register int j = i; j <= 71; ++j){
			for(register int l = 0; l < 75; ++l) dp[i][j][l] = dp[j][i][l] = inf;
		}
	}
	for(register int i = 1; i <= n; ++i) dp[i][i][0] = 0;
	for(register int i = 1, a, b, t; i <= m; ++i){
		cin >> a >> b >> t;
		dp[a][b][1] = min(dp[a][b][1], t);
	}
	cin >> K >> Q;
	for(register int k = 1; k < min(K+1, 71); ++k){
		for(register int i = 1; i <= n; ++i){
			for(register int j = 1; j <= n; ++j){
				for(register int l = 1; l <= n; ++l){
						if(dp[i][l][k - 1] != inf && dp[l][j][1] != inf) dp[i][j][k] = min(dp[i][j][k], dp[i][l][k - 1] + dp[l][j][1]);
				}
			}
		}
	}
	int u, v;
	while(Q--){
		cin >> u >> v;
		int ans = inf;
		for(register int i = 0; i < min(K + 1, 71); ++i){
			ans = min(ans, dp[u][v][i]);
		}
		cout << (ans == inf ? -1 : ans) << '\n';
	}
	return 0;
}