#include<bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int sz = 500005;
pair<ll, ll> A[sz];
ll pref[sz], cost[sz];

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	for(register int i(1); i <= N; ++i) cin >> A[i].first >> A[i].second;
	sort(A+1, A+N+1);
	for(register int i(1); i <= N; ++i) pref[i] = pref[i-1] + A[i].second;
	cost[N] = pref[N] - A[N].first;
	for(register int i(N - 1); i >= 1; --i) cost[i] = max(cost[i+1], pref[i] - A[i].first);
	long long ans{-10000000000};
	for(register int i(1); i <= N; ++i) ans = max(ans, cost[i] - (pref[i-1] - A[i].first));
	cout << ans << '\n';
	return 0;
}