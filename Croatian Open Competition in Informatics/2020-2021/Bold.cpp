#include<bits/stdc++.h>

using namespace std;

constexpr int sz = 2e5 + 5;

int n, m;
bool h[101][101];
string c;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= n; ++i){
		cin >> c;
		for(register int j = 1; j <= m; ++j){
			if(c[j-1] == '#'){
				h[i][j] = h[i+1][j] = h[i][j+1] = h[i+1][j+1] = true;
			}
		}
	}
	for(register int i = 1; i <= n; ++i){
		for(register int j = 1; j <= m; ++j){
			cout << (h[i][j] ? '#' : '.');
		}
		cout << '\n';
	}
	return 0;
}