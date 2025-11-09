#include<bits/stdc++.h>
using namespace std;

int n, l, r, t[1000001];

bool check(int dif){
	deque<int> q = {0};
	int i(l);
	while(i <= n && !q.empty()){
		if(i - q.front() >= l){
			if(i - q.front() <= r && t[i] - t[q.front()+1] <= dif){
				q.push_back(i), ++i;
			}else{
				q.pop_front();
			}
		}else{
			++i;
		}
	}
	return (!q.empty() && q.back() == n);
}

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l >> r;
	for(register int i = 1; i <= n; ++i) cin >> t[i];
	sort(t+1,t+n+1);
	int lo(0), hi(t[n]), mid, ans;
	while(lo <= hi){
		mid = lo + ((hi - lo) >> 1);
		if(check(mid)){
			hi = mid - 1, ans = mid;
		}else{
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
}