#include<bits/stdc++.h>

using namespace std;

constexpr int sz = 1e5 + 6;

string s;
int h, o, n, i;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	int ans(0);
	for(register int j = 0; j < (int)s.size(); ++j){
		h += s[j] == 'H';
		if(h) o += s[j] == 'O';
		if(o) n += s[j] == 'N';
		if(n) i += s[j] == 'I';
		if(h && o && n && i){
			++ans;
			h = o = n = i = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}