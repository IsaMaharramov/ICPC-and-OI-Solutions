#include<bits/stdc++.h>

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

constexpr int sz = 2002;
const int mod = 1e9 + 7;

int n, k;
long long dp[sz], C[sz][sz];
string s;
unordered_map<string, int> cnt;

int main(){
	speed;
	cin >> n >> k;
	for(register int i = 1; i <= n; ++i){
		cin >> s;
		sort(all(s));
		cnt[s]++;
	}
	C[1][0] = C[1][1] = 1;
	for(register int i = 2; i <= n; ++i){
		for(register int j = 0; j <= i; ++j){
			if(!j){
				C[i][0] = 1;
				continue;
			}
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
			C[i][j] %= mod;
		}
	}
	dp[0] = 1;
	for(auto &to : cnt){
		int ai = to.second;
		for(register int i = k; i >= 0; --i){
			for(register int take = 1; take <= ai && C[take][2] <= i; ++take){
				dp[i] += 1ll * dp[i - C[take][2]] * C[ai][take] % mod;
				dp[i] %= mod;
			}
		}
	}
	cout << dp[k] % mod << '\n';
	return 0;
}