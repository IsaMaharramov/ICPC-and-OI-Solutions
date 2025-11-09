#include<bits/stdc++.h>

/*

......

*/

using namespace std;

constexpr int sz = 2e5 + 5;

int n;
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int> h(n);
	for(auto &j : h) cin >> j;
	for(register int i = n - 1; i >= 0; --i){
		if(mp[h[i] - 1]){
			mp[h[i] - 1]--;
		}
		mp[h[i]]++;
	}
	int ans(0);
	for(auto &it : mp) ans += it.second;
	cout << ans << '\n';
	return 0;
}
/*


*/